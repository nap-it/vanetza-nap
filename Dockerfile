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
RUN printf "\nlistener 1883 0.0.0.0\nallow_anonymous true\n\n" > /etc/mosquitto/mosquitto.conf
RUN mkdir /vanetza
COPY . /vanetza
WORKDIR /vanetza
RUN dpkg -i deps/*.deb
RUN rm CMakeCache.txt
RUN cmake .
RUN cmake --build . --target socktap -j 8
RUN cp /vanetza/bin/socktap /usr/local/bin/socktap
RUN chmod +x /vanetza/entrypoint.sh
#SHELL ["/bin/bash", "-c"]
#ENTRYPOINT ["/usr/bin/sleep", " 5000"]
ENTRYPOINT ["/vanetza/entrypoint.sh"]
#ENTRYPOINT ["/usr/local/bin/socktap", "-l", "ethernet", "-i", "eth0", "-a", "ca", "--security=none", "--non-strict", "--gn-version", "1"]
#ENTRYPOINT ["/usr/local/bin/socktap", "-c", "tools/socktap/config.ini"]
