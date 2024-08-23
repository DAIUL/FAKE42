FROM debian:bullseye

EXPOSE 3306

ARG SQL_DATABASE=${SQL_DATABASE}
ARG SQL_USER=${SQL_USER}
ARG SQL_PASSWORD=${SQL_PASSWORD}
ARG SQL_ROOT_PASSWORD=${SQL_ROOT_PASSWORD}

RUN apt-get update && apt-get install mariadb-server -y

RUN rm /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./conf/docker-entrypoint.sh /.
RUN chmod 755 /docker-entrypoint.sh && chmod 755 /etc/mysql/mariadb.conf.d/50-server.cnf

ENTRYPOINT ["./docker-entrypoint.sh"]
CMD ["mysqld_safe"]
