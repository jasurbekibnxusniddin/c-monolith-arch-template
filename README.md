# c-monolith-arch-template
c monolith arch template 

## install

1. install libpq and libmicrohttpd
```bash 
brew install libpq libmicrohttpd
```
```sh
sudo apt update
sudo apt install libpq-dev libmicrohttpd-dev
```

2. install libpq and libmicrohttpd into the project
```bash
make lib-install-darwin
make lib-install-linux
```
## used libraries
[libpq](https://www.postgresql.org/docs/current/libpq.html) <br>
[libmicrohttpd](https://www.gnu.org/software/libmicrohttpd/)
