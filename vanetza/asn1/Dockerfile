FROM ubuntu:latest AS base

FROM base AS build
RUN apt-get update && apt-get install -y autoconf automake bison build-essential flex git libtool
# asn1c source is provided as a tarball created by `git archive` from a local clone
# because the required commit is not directly fetchable from GitHub's remote
COPY vanetza/asn1/asn1c-source.tar.gz /asn1c-source.tar.gz
RUN mkdir /asn1c-source && tar xzf /asn1c-source.tar.gz -C /asn1c-source
WORKDIR /asn1c-source
RUN autoreconf -iv && ./configure --prefix /asn1c && make -j $(nproc) install

FROM base AS runtime
RUN apt-get update && apt-get install -y cmake
COPY --from=build /asn1c/bin /usr/bin
COPY --from=build /asn1c/share /usr/share
RUN mkdir -p /asn1c/share && ln -s /usr/share/asn1c /asn1c/share/asn1c
