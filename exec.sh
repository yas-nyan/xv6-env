docker start xv6-ubuntu
docker exec -it `docker ps | grep xv6-ubuntu | awk '{print $1}'` bash
