FROM debian:10.12

RUN apt-get update -y
RUN apt-get install -y --no-install-recommends apt-utils
RUN apt-get install gcc -y
RUN apt-get install make -y
RUN apt-get install git -y
RUN apt-get install vim -y
RUN apt-get install clang -y
RUN apt-get install valgrind -y
RUN apt-get install python3 -y
RUN apt-get install python3-venv python3-pip -y
RUN python3 -m pip install --upgrade pip setuptools
RUN python3 -m pip install norminette

WORKDIR ./

CMD ["tail", "-f", "/dev/null"]