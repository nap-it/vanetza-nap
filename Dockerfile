FROM debian:buster-slim
ENV TZ=Europe/Lisbon
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN printf "deb http://httpredir.debian.org/debian buster-backports main non-free\ndeb-src http://httpredir.debian.org/debian buster-backports main non-free" > /etc/apt/sources.list.d/backports.list
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake/buster-backports \
    git \
    mosquitto \
    libboost-date-time-dev \
    libmosquittopp-dev \
    libboost-program-options-dev \
    nlohmann-json3-dev/buster-backports \
    libboost-system-dev \
    libcrypto++-dev \
    libgeographic-dev \
    libgps-dev/buster-backports \
    libssl-dev \
    libnl-3-dev \
    libnl-genl-3-dev \
    zlib1g-dev \
    libcurl4-openssl-dev \
    golang-src/buster-backports \
    golang-go/buster-backports \
    ca-certificates \
    file \
    && rm -rf /var/lib/apt/lists/*
RUN mkdir /vanetza
COPY . /vanetza
WORKDIR /tmp
RUN git clone https://github.com/jupp0r/prometheus-cpp.git
WORKDIR /tmp/prometheus-cpp
RUN git submodule update --init
RUN cmake -B_build -DCPACK_GENERATOR=DEB -DBUILD_SHARED_LIBS=ON
RUN cmake --build _build --target package --parallel $(nproc)
RUN dpkg -i _build/*.deb
WORKDIR /vanetza
RUN rm -f CMakeCache.txt
RUN cmake .
RUN cmake --build . --target socktap -j $(nproc)
RUN cp /vanetza/bin/socktap /usr/local/bin/socktap
RUN mkdir -p /root/go/src/dds-vanetza-service
RUN cp -r /vanetza/tools/dds_service/* /root/go/src/dds-vanetza-service
WORKDIR /root/go/src/dds-vanetza-service
RUN GOMAXPROCS=1 GO111MODULE="on" go mod tidy
RUN chmod +x build.sh
RUN ./build.sh
WORKDIR /vanetza

FROM debian:buster-slim
ENV TZ=Europe/Lisbon
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN printf "deb http://httpredir.debian.org/debian buster-backports main non-free\ndeb-src http://httpredir.debian.org/debian buster-backports main non-free" > /etc/apt/sources.list.d/backports.list
RUN apt-get update && apt-get install -y --no-install-recommends \
    mosquitto \
    libboost-date-time1.67.0 \
    libmosquittopp1 \
    libboost-program-options1.67.0 \
    nlohmann-json3-dev \
    libboost-system1.67.0 \
    libcrypto++ \
    libgeographic17 \
    libnl-3-dev \
    libnl-genl-3-dev \
    libssl1.1 \
    zlib1g \
    iproute2/buster-backports \
    libgps-dev/buster-backports \
    iptables \
    bridge-utils \
    ebtables \
    tcpdump \
    libcurl4-openssl-dev \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /
ENV EMBEDDED_MOSQUITTO_PORT=1883
COPY --from=0 /vanetza/bin/socktap /usr/local/bin/socktap
COPY --from=0 /root/go/src/dds-vanetza-service/Vanetza_DDS_Spec.xml /Vanetza_DDS_Spec.xml
COPY --from=0 /vanetza/tools/socktap/config.ini /config.ini
COPY --from=0 /vanetza/entrypoint.sh /entrypoint.sh
COPY --from=0 /root/go/src/dds-vanetza-service/main /root/go/src/dds-vanetza-service/main
COPY --from=0 /root/go/src/dds-vanetza-service/main /root/go/src/dds-vanetza-service/main
COPY --from=0 /root/go/pkg/mod/github.com/rticommunity/ /root/go/pkg/mod/github.com/rticommunity/
COPY --from=0 /tmp/prometheus-cpp/_build/*.deb /deps/
RUN dpkg -i /deps/*.deb
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]
