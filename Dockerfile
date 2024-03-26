FROM debian:bullseye-slim
ENV TZ=Europe/Lisbon
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN printf "deb http://httpredir.debian.org/debian bullseye-backports main non-free\ndeb-src http://httpredir.debian.org/debian bullseye-backports main non-free\n" > /etc/apt/sources.list.d/backports.list
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake/bullseye-backports \
    cmake-data/bullseye-backports \
    git \
    mosquitto \
    libboost-date-time-dev \
    libmosquittopp-dev \
    libboost-program-options-dev \
    libboost-system-dev \
    libasio-dev \
    libtinyxml2-dev \
    libcrypto++-dev \
    libgeographic-dev \
    libgps-dev \
    libssl-dev \
    libnl-3-dev \
    libnl-genl-3-dev \
    zlib1g-dev \
    libcurl4-openssl-dev \
    ca-certificates \
    file \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /tmp
RUN git clone https://github.com/jupp0r/prometheus-cpp.git
WORKDIR /tmp/prometheus-cpp
RUN git submodule update --init
RUN git checkout a944ec100251019cd44d070bbf2fd22f5139d6d0
RUN cmake -B_build -DCPACK_GENERATOR=DEB -DBUILD_SHARED_LIBS=ON
RUN cmake --build _build --target package --parallel $(nproc)
RUN dpkg -i _build/*.deb
WORKDIR /tmp
RUN git clone https://github.com/eProsima/foonathan_memory_vendor.git
RUN mkdir /tmp/foonathan_memory_vendor/build
WORKDIR /tmp/foonathan_memory_vendor/build
RUN cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local/ -DBUILD_SHARED_LIBS=ON
RUN cmake --build . --target install --parallel $(nproc)
WORKDIR /tmp
RUN git clone https://github.com/eProsima/Fast-CDR.git
RUN mkdir /tmp/Fast-CDR/build
WORKDIR /tmp/Fast-CDR/build
RUN cmake ..
RUN cmake --build . --target install --parallel $(nproc)
WORKDIR /tmp
RUN git clone https://github.com/eProsima/Fast-DDS.git
WORKDIR /tmp/Fast-DDS/
RUN git checkout v2.13.2
RUN mkdir /tmp/Fast-DDS/build
WORKDIR /tmp/Fast-DDS/build
RUN cmake ..
RUN cmake --build . --target install --parallel $(nproc)
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
    libtinyxml2-8 \
    libcrypto++ \
    libgeographic19 \
    libnl-3-dev \
    libnl-genl-3-dev \
    libssl1.1 \
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
COPY --from=0 /vanetza/bin/socktap /usr/local/bin/socktap
COPY --from=0 /vanetza/tools/socktap/config.ini /config.ini
COPY --from=0 /vanetza/entrypoint.sh /entrypoint.sh
COPY --from=0 /usr/local/lib/libfast* /usr/local/lib
COPY --from=0 /usr/local/lib/libfoon* /usr/local/lib
COPY --from=0 /tmp/prometheus-cpp/_build/*.deb /deps/
RUN dpkg -i /deps/*.deb
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]
