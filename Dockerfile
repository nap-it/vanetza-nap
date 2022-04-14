FROM ubuntu:impish
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
    nlohmann-json3-dev \
    libboost-system-dev \
    libcrypto++-dev \
    libgeographic-dev \
    libssl-dev \
    zlib1g-dev \
    libcurl4-openssl-dev \
    && rm -rf /var/lib/apt/lists/*
#COPY bin/socktap /usr/local/bin/socktap
#COPY docker_script.sh /usr/local/bin/docker_script.sh
#RUN chmod +x /usr/local/bin/docker_script.sh
RUN mkdir /vanetza
COPY . /vanetza
WORKDIR /vanetza
RUN dpkg -i deps/*.deb
RUN rm CMakeCache.txt
RUN cmake .
RUN cmake --build . --target socktap -j 8
RUN cp /vanetza/bin/socktap /usr/local/bin/socktap
#SHELL ["/bin/bash", "-c"]
#ENTRYPOINT ["/usr/bin/sleep", " 5000"]
#ENTRYPOINT ["/usr/local/bin/docker_script.sh"]
ENTRYPOINT ["/usr/local/bin/socktap", "-l", "ethernet", "-i", "eth0", "-a", "ca", "--security=none", "--non-strict", "--gn-version", "1"]
