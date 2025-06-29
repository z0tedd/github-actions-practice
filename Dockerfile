# Используем официальный образ с установленным Drogon и компилятором
FROM ubuntu:22.04 AS first 

# Установка зависимостей
RUN apt-get update && \
  apt-get install -y git cmake build-essential libssl-dev uuid-dev curl pkg-config

# Устанавливаем Drogon через vcpkg
RUN git clone https://github.com/microsoft/vcpkg.git  && \
  cd vcpkg && \
  ./bootstrap-vcpkg.sh && \
  ./vcpkg install drogon

ENV PATH="/vcpkg:${PATH}"
ENV VCPKG_ROOT=/vcpkg
# Копируем исходники
WORKDIR /app
COPY . .

# Сборка приложения
RUN  mkdir build && cd build && cmake .. && make


RUN ls -al /app/build

FROM ubuntu:22.04

WORKDIR /app

RUN apt-get update && \
  apt-get install libc6 libstdc++6

COPY --from=first /app/build/hello-server .
COPY --from=first /app/config.json .
RUN ls -a .
# Запуск сервера
CMD ["./hello-server"]
