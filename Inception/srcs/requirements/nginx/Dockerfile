FROM debian:bullseye

EXPOSE	443

RUN apt update
RUN apt install nginx -y
RUN apt install vim -y
RUN mkdir -p /etc/nginx/ssl

RUN apt install openssl -y
RUN openssl req -x509 -days 365 -nodes -newkey rsa:4096 \
	-keyout /etc/nginx/ssl/inception.key \
	-out /etc/nginx/ssl/inception.crt -sha256 -subj "/CN=qpuig.42.fr"

RUN mkdir -p /var/run/nginx

COPY ./nginx.conf /etc/nginx/sites-available/default

RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

CMD [ "nginx", "-g", "daemon off;" ]