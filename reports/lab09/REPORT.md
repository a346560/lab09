## Laboratory work IX

Данная лабораторная работа посвещена изучению процесса создания пакета на примере **Github Release**

```ShellSession
$ open https://help.github.com/articles/creating-releases/
```

## Tasks

- [V] 1. Создать публичный репозиторий с названием **lab09** на сервисе **GitHub**
https://github.com/a346560/lab09
- [V] 2. Ознакомиться со ссылками учебного материала
- [V] 3. Получить токен для доступа к репозиториям сервиса **GitHub**
d06a8730ac40302bc51c9d4fdee40b3ff894b231
- [V] 4. Выполнить инструкцию учебного материала
Установка github-release на рабочую машину невозможно вследствии использования архитектуры х86. Продукт требует архитектуры х64.
- [V] 5. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ export GITHUB_TOKEN=1d73f7966000dcf1ccdc0943c19acf6b557047c9
$ export GITHUB_USERNAME=a346560
```

```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab08 lab09
$ cd lab09
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab09
```

```ShellSession
$ sed -i '' 's/lab08/lab09/g' README.md
```

```ShellSession
$ cmake -H. -B_build -DCPACK_GENERATOR="TGZ"
-- The C compiler identification is GNU 5.4.0
-- The CXX compiler identification is GNU 5.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/user/vershinin/lab09/_build
$ cmake --build _build --target package
Run CPack packaging tool...
CPack: Create package using TGZ
CPack: Install projects
CPack: - Run preinstall target for: print
CPack: - Install project: print
CPack: Create package
CPack: - package: /home/user/vershinin/lab09/_build/print--.tar.gz generated.

```

```ShellSession
$ travis login --auto
We need your GitHub login to identify you.
This information will not be sent to Travis CI, only to api.github.com.
The password will not be displayed.

Try running with --github-token or --auto if you don't want to enter your password anyway.

Username: a346560
Password for a346560: ********
Successfully logged in as a346560!
$ travis enable
Detected repository as a346560/lab09, is this correct? |yes| 
a346560/lab09: enabled :)
```

```ShellSession
$ git tag v0.1.0.0
$ git push origin master --tags
```

```ShellSession
$ github-release --version
github-release v0.7.2
$ github-release info -u ${GITHUB_USERNAME} -r lab09
tags:
- v0.1.0.0 (commit: https://api.github.com/repos/a346560/lab09/commits/7f8ae63af3b121b8177a0b96bed6b9114386a30a)
releases:
$ github-release release \
    --user ${GITHUB_USERNAME} \
    --repo lab09 \
    --tag v0.1.0.0 \
    --name "libprint" \
    --description "my first release"
```

```ShellSession
$ export PACKAGE_OS=`uname -s` PACKAGE_ARCH=`uname -m` 
$ export PACKAGE_FILENAME=print-${PACKAGE_OS}-${PACKAGE_ARCH}.tar.gz
$ github-release upload \
    --user ${GITHUB_USERNAME} \
    --repo lab09 \
    --tag v0.1.0.0 \
    --name "${PACKAGE_FILENAME}" \
    --file _build/*.tar.gz
```

```ShellSession
$ github-release info -u ${GITHUB_USERNAME} -r lab09
tags:
- v0.1.0.0 (commit: https://api.github.com/repos/a346560/lab09/commits/7f8ae63af3b121b8177a0b96bed6b9114386a30a)
releases:
- v0.1.0.0, name: 'libprint', description: 'my first release', id: 6826938, tagged: 24/06/2017 at 09:17, published: 25/06/2017 at 09:15, draft: ✗, prerelease: ✗
  - artifact: print-Linux-x86_64.tar.gz, downloads: 0, state: uploaded, type: application/octet-stream, size: 2.6 kB, id: 4178819
$ wget https://github.com/${GITHUB_USERNAME}/lab09/releases/download/v0.1.0.0/${PACKAGE_FILENAME}
--2017-06-25 12:21:00--  https://github.com/a346560/lab09/releases/download/v0.1.0.0/print-Linux-x86_64.tar.gz
Распознаётся github.com (github.com)... 192.30.253.112, 192.30.253.113
Подключение к github.com (github.com)|192.30.253.112|:443... соединение установлено.
HTTP-запрос отправлен. Ожидание ответа... 302 Found
Адрес: https://github-production-release-asset-2e65be.s3.amazonaws.com/95286406/8217644c-59a0-11e7-8150-44fd59447c20?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAIWNJYAX4CSVEH53A%2F20170625%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20170625T092135Z&X-Amz-Expires=300&X-Amz-Signature=5800df1b40f61626e9c43ba0c94d7e16d96a3dd76b92db8b6f695d4e70ab20c6&X-Amz-SignedHeaders=host&actor_id=0&response-content-disposition=attachment%3B%20filename%3Dprint-Linux-x86_64.tar.gz&response-content-type=application%2Foctet-stream [переход]
--2017-06-25 12:21:01--  https://github-production-release-asset-2e65be.s3.amazonaws.com/95286406/8217644c-59a0-11e7-8150-44fd59447c20?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAIWNJYAX4CSVEH53A%2F20170625%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20170625T092135Z&X-Amz-Expires=300&X-Amz-Signature=5800df1b40f61626e9c43ba0c94d7e16d96a3dd76b92db8b6f695d4e70ab20c6&X-Amz-SignedHeaders=host&actor_id=0&response-content-disposition=attachment%3B%20filename%3Dprint-Linux-x86_64.tar.gz&response-content-type=application%2Foctet-stream
Распознаётся github-production-release-asset-2e65be.s3.amazonaws.com (github-production-release-asset-2e65be.s3.amazonaws.com)... 54.231.97.224
Подключение к github-production-release-asset-2e65be.s3.amazonaws.com (github-production-release-asset-2e65be.s3.amazonaws.com)|54.231.97.224|:443... соединение установлено.
HTTP-запрос отправлен. Ожидание ответа... 200 OK
Длина: 2644 (2,6K) [application/octet-stream]
Сохранение в каталог: ««print-Linux-x86_64.tar.gz»».

print-Linux-x86_64.tar.gz           100%[=================================================================>]   2,58K  --.-KB/s    in 0s      

2017-06-25 12:21:02 (105 MB/s) - «print-Linux-x86_64.tar.gz» сохранён [2644/2644]

$ tar -ztf ${PACKAGE_FILENAME}
print--/include/
print--/include/print.hpp
print--/cmake/
print--/cmake/print-config-noconfig.cmake
print--/cmake/print-config.cmake
print--/lib/
print--/lib/libprint.a

```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=09
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m"lab${LAB_NUMBER}"
```

## Links

- [Create Release](https://help.github.com/articles/creating-releases/)
- [Get GitHub Token](https://help.github.com/articles/creating-a-personal-access-token-for-the-command-line/)
- [Go Setup](http://www.golangbootcamp.com/book/get_setup)
- [github-release](https://github.com/aktau/github-release)

```
Copyright (c) 2017 Братья Вершинины
```
