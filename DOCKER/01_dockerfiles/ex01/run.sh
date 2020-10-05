#!/bin/sh
docker build -t ex01 .

docker run -d --name teamspeak --rm -p 9987:9987/udp -p 10011:10011 -p 30033:30033 ex01

echo "Server is running. Connect with local client to $(ipconfig getifaddr en0)."
echo "When finished, run \`docker stop teamspeak\`"
echo "Password:" $(docker logs teamspeak | grep token | awk '{print $5}')
