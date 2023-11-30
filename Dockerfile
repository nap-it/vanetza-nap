FROM debian:bullseye-slim
ENV TZ=Europe/Lisbon
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
#RUN printf "deb http://httpredir.debian.org/debian buster-backports main non-free\ndeb-src http://httpredir.debian.org/debian buster-backports main non-free\n" > /etc/apt/sources.list.d/backports.list
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    git \
    mosquitto \
    libboost-date-time-dev \
    libmosquittopp-dev \
    libboost-program-options-dev \
    libboost-system-dev \
    libcrypto++-dev \
    libgeographic-dev \
    libgps-dev \
    libssl-dev \
    libnl-3-dev \
    libnl-genl-3-dev \
    zlib1g-dev \
    libfastcdr-dev \
    libfastrtps-dev \
    libcurl4-openssl-dev \
    ca-certificates \
    file \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /tmp
RUN git clone https://github.com/jupp0r/prometheus-cpp.git
WORKDIR /tmp/prometheus-cpp
RUN git submodule update --init
RUN cmake -B_build -DCPACK_GENERATOR=DEB -DBUILD_SHARED_LIBS=ON
RUN cmake --build _build --target package --parallel $(nproc)
RUN dpkg -i _build/*.deb
RUN mkdir /vanetza
COPY . /vanetza
WORKDIR /vanetza
RUN rm -f CMakeCache.txt
RUN cmake .
RUN cmake --build . --target socktap -j $(nproc)
RUN cp /vanetza/bin/socktap /usr/local/bin/socktap

FROM debian:bullseye-slim
ENV TZ=Europe/Lisbon
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
#RUN printf "deb http://httpredir.debian.org/debian buster-backports main non-free\ndeb-src http://httpredir.debian.org/debian buster-backports main non-free\n" > /etc/apt/sources.list.d/backports.list
RUN apt-get update && apt-get install -y --no-install-recommends \
    mosquitto \
    libboost-date-time1.74.0 \
    libmosquittopp1 \
    libboost-program-options1.74.0 \
    libboost-system1.74.0 \
    libcrypto++ \
    libgeographic19 \
    libnl-3-dev \
    libnl-genl-3-dev \
    libssl1.1 \
    zlib1g \
    libfastcdr1 \
    libfastrtps2 \
    iproute2 \
    libgps-dev \
    iptables \
    bridge-utils \
    ebtables \
    tcpdump \
    libcurl4-openssl-dev \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/* \
    && rm -rf /usr/lib/ocaml \
    && rm -rf /usr/bin/ocam* \
    && rm -rf /usr/lib/$(uname -m)-linux-gnu/perl \
    && rm -rf /usr/lib/$(uname -m)-linux-gnu/perl-base \
    && rm -rf /usr/lib/$(uname -m)-linux-gnu/libperl*\
    && rm -rf /usr/share/perl \
    && rm -rf /usr/bin/perl \
    && rm -rf /usr/share/doc/*  
WORKDIR /
ENV EMBEDDED_MOSQUITTO_PORT=1883
COPY --from=0 /vanetza/bin/socktap /usr/local/bin/socktap
COPY --from=0 /vanetza/tools/socktap/config.ini /config.ini
COPY --from=0 /vanetza/entrypoint.sh /entrypoint.sh
COPY --from=0 /tmp/prometheus-cpp/_build/*.deb /deps/
RUN dpkg -i /deps/*.deb
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]
