FROM debian

RUN apt-get update -y && \
	apt-get upgrade -y && \
	apt-get install wget -y && \
	apt-get install bzip2 -y && \
	wget https://files.teamspeak-services.com/releases/server/3.10.2/teamspeak3-server_linux_amd64-3.10.2.tar.bz2 && \
	tar xvf teamspeak3-server_linux_amd64-3.10.2.tar.bz2 && \
	rm teamspeak3-server_linux_amd64-3.10.2.tar.bz2 && \
	touch teamspeak3-server_linux_amd64/.ts3server_license_accepted

CMD teamspeak3-server_linux_amd64/ts3server_minimal_runscript.sh
