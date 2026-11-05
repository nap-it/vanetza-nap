FROM code.nap.av.it.pt:5050/mobility-networks/middleware-images/zenoh-libs:1.4.0-bookworm AS zenoh-libs
FROM code.nap.av.it.pt:5050/external-tools/misc-docker-images/debian:bookworm-slim AS build

COPY --from=zenoh-libs /usr/local /usr/local

ENV TZ=Europe/Lisbon
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    git \
    mosquitto \
    libboost-date-time-dev \
    libmosquittopp-dev \
    libboost-program-options-dev \
    libboost-system-dev \
    libasio-dev \
    libtinyxml2-dev \
    libcrypto++-dev \
    libgeographiclib-dev \
    libgps-dev \
    libssl-dev \
    libnl-3-dev \
    libnl-genl-3-dev \
    zlib1g-dev \
    libcurl4-openssl-dev \
    ca-certificates \
    file \
    && rm -rf /var/lib/apt/lists/*


# Prometheus dependencies
WORKDIR /tmp
RUN git clone https://github.com/jupp0r/prometheus-cpp.git
WORKDIR /tmp/prometheus-cpp
RUN git checkout a944ec100251019cd44d070bbf2fd22f5139d6d0
RUN git submodule update --init
RUN cmake -B_build -DCPACK_GENERATOR=DEB -DBUILD_SHARED_LIBS=ON
RUN cmake --build _build --target package --parallel $(nproc)
RUN dpkg -i _build/*.deb

# DDS dependencies
WORKDIR /tmp
RUN git clone https://github.com/eProsima/foonathan_memory_vendor.git
RUN mkdir /tmp/foonathan_memory_vendor/build
WORKDIR /tmp/foonathan_memory_vendor/build
RUN cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local/ -DBUILD_SHARED_LIBS=ON
RUN cmake --build . --target install --parallel $(nproc)
WORKDIR /tmp
RUN git clone https://github.com/eProsima/Fast-CDR.git
WORKDIR /tmp/Fast-CDR/
RUN git checkout v2.2.6
RUN mkdir /tmp/Fast-CDR/build
WORKDIR /tmp/Fast-CDR/build
RUN cmake ..
RUN cmake --build . --target install --parallel $(nproc)
WORKDIR /tmp
RUN git clone https://github.com/eProsima/Fast-DDS.git
WORKDIR /tmp/Fast-DDS/
RUN git checkout v2.14.6
RUN mkdir /tmp/Fast-DDS/build
WORKDIR /tmp/Fast-DDS/build
RUN cmake ..
RUN cmake --build . --target install --parallel $(nproc)

# Vanetza
RUN mkdir /vanetza
COPY . /vanetza
WORKDIR /vanetza
RUN rm -f CMakeCache.txt
RUN cmake .
RUN cmake --build . --target socktap -j $(nproc)
RUN cp /vanetza/bin/socktap /usr/local/bin/socktap

FROM code.nap.av.it.pt:5050/external-tools/misc-docker-images/debian:bookworm-slim AS final
ENV TZ=Europe/Lisbon
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
#RUN printf "deb http://httpredir.debian.org/debian buster-backports main non-free\ndeb-src http://httpredir.debian.org/debian buster-backports main non-free\n" > /etc/apt/sources.list.d/backports.list
RUN apt-get update && apt-get install -y --no-install-recommends \
    mosquitto \
    libboost-date-time1.74.0 \
    libmosquittopp1 \
    libboost-program-options1.74.0 \
    libboost-system1.74.0 \
    libtinyxml2-9 \
    libcrypto++8 \
    libgeographiclib23 \
    libnl-3-dev \
    libnl-genl-3-dev \
    libssl3 \
    zlib1g \
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
COPY --from=build /vanetza/bin/socktap /usr/local/bin/socktap
COPY --from=build /vanetza/tools/socktap/config.ini /config.ini
COPY --from=build /vanetza/tools/socktap/zenoh_config.json5 /zenoh_config.json5
COPY --from=build /vanetza/entrypoint.sh /entrypoint.sh
COPY --from=build /usr/local/lib/libfast* /usr/local/lib/
COPY --from=build /usr/local/lib/libfoon* /usr/local/lib/
COPY --from=build /tmp/prometheus-cpp/_build/*.deb /deps/
COPY --from=build /usr/local/lib/libzenoh* /usr/local/lib/
RUN dpkg -i /deps/*.deb
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]
