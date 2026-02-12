# syntax=docker/dockerfile:1

ARG VANETZA_REF=master

FROM code.nap.av.it.pt:5050/external-tools/misc-docker-images/debian:bullseye-slim AS build
ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=UTC
RUN ln -snf /usr/share/zoneinfo/${TZ} /etc/localtime && echo ${TZ} > /etc/timezone
RUN printf "deb http://archive.debian.org/debian-archive/debian bullseye-backports main non-free\ndeb-src http://archive.debian.org/debian-archive/debian bullseye-backports main non-free\n" > /etc/apt/sources.list.d/backports.list
RUN apt-get update && apt-get install -y --no-install-recommends \
        build-essential \
        ca-certificates \
        cmake \
        git \
        libboost-date-time-dev \
        libboost-program-options-dev \
        libboost-system-dev \
        libcrypto++-dev \
        libgeographic-dev \
        libssl-dev \
        ninja-build \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /opt
COPY . /opt/vanetza
WORKDIR /opt/vanetza
RUN cmake -S . -B build -G Ninja \
        -DBUILD_SOCKTAP=ON \
        -DBUILD_CERTIFY=OFF \
        -DBUILD_BENCHMARK=OFF \
        -DBUILD_TESTS=OFF \
        -DBUILD_FUZZ=OFF \
    && cmake --build build --target socktap

FROM code.nap.av.it.pt:5050/external-tools/misc-docker-images/debian:bullseye-slim AS runtime
ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=UTC
RUN ln -snf /usr/share/zoneinfo/${TZ} /etc/localtime && echo ${TZ} > /etc/timezone
RUN apt-get update && apt-get install -y --no-install-recommends \
        ca-certificates \
        libboost-date-time-dev \
        libboost-program-options-dev \
        libboost-system-dev \
        libcrypto++-dev \
        libgeographic-dev \
        libssl-dev \
        gpsd-clients \
    && rm -rf /var/lib/apt/lists/*

COPY --from=build /opt/vanetza/build/bin/socktap /opt/vanetza/socktap

ENV VANETZA_HOME=/opt/vanetza
WORKDIR /opt/vanetza
ENTRYPOINT ["/bin/bash"]
