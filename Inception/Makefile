all : build

build : 
	@sudo hostsed add 127.0.0.1 qpuig.42.fr && echo "\033[1;38;2;255;117;24m|ADD qpuig.42.fr to /etc/hosts|\033[0m"\
	@docker-compose -f ./srcs/docker-compose.yml up -d 

down : 
	@sudo hostsed rm 127.0.0.1 qpuig.42.fr && echo "\033[1;38;2;255;117;24m|DELETE qpuig.42.fr from /etc/hosts|~\033[0m"
	@docker-compose -f ./srcs/docker-compose.yml down

stop : 
	@docker-compose -f ./srcs/docker-compose.yml stop

start : 
	@docker-compose -f ./srcs/docker-compose.yml start

status : 
	@docker ps

delete : down
	@docker image rm wordpress -f
	@docker image rm mariadb -f
	@docker image rm nginx -f
	@docker volume rm mariadb
	@docker volume rm wordpress && echo "\033[1;38;2;255;117;24m| Nettoyage des images/containers/volumes de Docker : OK |~\033[0m"\
	
prune :
	@sudo rm -rf /home/user/data/wordpress/*
	@sudo rm -rf /home/user/data/mariadb/*
	@docker system prune -af && echo "\033[1;38;2;255;117;24m| Nettoyage du cache de Docker : OK |~\033[0m"\

