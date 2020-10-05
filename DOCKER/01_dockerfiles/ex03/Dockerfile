FROM	ubuntu

RUN		apt-get -y update && \
		apt-get -y upgrade && \
		echo "postfix postfix/mailname string example.com" | debconf-set-selections && \
		echo "postfix postfix/main_mailer_type string 'Internet Site'" | debconf-set-selections && \
		apt-get install -y curl ca-certificates postfix && \
		curl -s https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | bash && \
		apt install -y gitlab-ce
ENV		DEBIAN_FRONTEND=noninteractive
RUN		apt-get install -y tzdata
RUN		mkdir -p /etc/gitlab/ssl/ && \
		chmod 700 /etc/gitlab/ssl/ && \
		cd /etc/gitlab/ssl/ && \
		openssl genrsa -out init.jsabina.com.key 2048 && \
		openssl req -new -x509 -nodes -days 42 -key init.jsabina.com.key -out init.jsabina.com.crt \
		-subj "/C=RU/ST=Moscow/L=Moscow/O=21-school/OU=42/CN=init.jsabina.com" && \
		echo "letsencrypt['enable'] = false" >> /etc/gitlab/gitlab.rb && \
		sed -i "s/^external_url.*/external_url \'https:\/\/init.jsabina.com\'/" /etc/gitlab/gitlab.rb && \
		echo "gitlab_rails['gitlab_shell_ssh_port'] = 22" >> /etc/gitlab/gitlab.rb
RUN		(/opt/gitlab/embedded/bin/runsvdir-start &) && \
		gitlab-ctl reconfigure
CMD 	(/opt/gitlab/embedded/bin/runsvdir-start &) && \
		gitlab-ctl start && \
		service ssh start && \
		gitlab-ctl tail

#How to test it
#docker-machine create --driver virtualbox --virtualbox-memory 3072 --virtualbox-cpu-count 3 gitlab
#docker build . -t mygitlab
#docker run -d -p 50022:22 -p 443:443 -p 80:80 --privileged mygitlab
#Now server is up and aviable on https://localhost
#Open it in Safari and verify Certificate
#It may show a 502 error, try to refresh
#Add a new root password
#You can log in as a root or you can create a new user
#Create a new repository and try to git clone it with https "https://localhost/root/EXAMPLE.git"
#--SSH PART--#
#To test ssh create a new repository and go to ADD_SSH
#Clear up known_hosts to prevent mitm attack
#pbcopy < /Users/lcharlin/.ssh/id_rsa.pub
#copy it to the site and save ssh
#ssh -p 50022 -T git@192.168.22.123 (MAC ip) to test if everything is OK
#Time to test clone and push through ssh
#git clone ssh://git@localhost:50022/root/testssh.git
#------------#
#That's it!
