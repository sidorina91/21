FROM ruby:2.4.1
RUN apt-get update -y && apt-get upgrade -y && apt-get install nodejs -y
ONBUILD COPY myapp /opt/app
ONBUILD WORKDIR /opt/app
ONBUILD EXPOSE 3000
ONBUILD RUN bundle install
ONBUILD RUN rake db:migrate
ONBUILD RUN rake db:seed
 
# creat mkdir rails mv Dockerfile
# docker build -t ft-rails:on-build .
# git clone https://github.com/RailsApps/myapp

###############################################
# FROM        ft-rails:on-build
# EXPOSE         3000
# CMD         ["rails", "s", "-b", "0.0.0.0", "-p", "3000"]
###############################################

# docker build -t learn-rails .
# docker run -d -p 3000:3000  learn-rails
