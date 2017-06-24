## Laboratory work VII

Данная лабораторная работа посвещена изучению систем документирования исходного кода на примере **Doxygen**

```ShellSession
$ open https://www.stack.nl/~dimitri/doxygen/manual/index.html
```

## Tasks

- [ ] 1. Создать публичный репозиторий с названием **lab07** на сервисе **GitHub**

- [ ] 2. Выполнить инструкцию учебного материала
- [ ] 3. Ознакомиться со ссылками учебного материала
- [ ] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ export GITHUB_USERNAME=<имя_пользователя>
$ alias edit=<nano|vi|vim|subl>
```

```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab06 lab07
$ cd lab07
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab07
```

```ShellSession
$ mkdir docs
$ doxygen -g docs/doxygen.conf
$ edit docs/doxygen.conf
```

```ShellSession
$ sed -i '' 's/\(PROJECT_NAME.*=\).*$/\1 print/g' docs/doxygen.conf
$ sed -i '' 's/\(EXAMPLE_PATH.*=\).*$/\1 examples/g' docs/doxygen.conf
$ sed -i '' 's/\(INCLUDE_PATH.*=\).*$/\1 examples/g' docs/doxygen.conf
$ sed -i '' 's/\(INPUT *=\).*$/\1 README.md include/g' docs/doxygen.conf
$ sed -i '' 's/\(USE_MDFILE_AS_MAINPAGE.*=\).*$/\1 README.md/g' docs/doxygen.conf
$ sed -i '' 's/\(OUTPUT_DIRECTORY.*=\).*$/\1 docs/g' docs/doxygen.conf
```

```ShellSession
$ sed -i '' 's/lab06/lab07/g' README.md
```

```ShellSession
$ git add .
$ git commit -m"added doxygen.conf"
$ git push origin master
```

```ShellSession
$ travis login --auto
$ travis enable
```

```
$ doxygen docs/doxygen.conf
$ ls | grep "[^docs]" | xargs rm -rf
$ mv docs/html/* . && rm -rf docs
$ git checkout -b gh-pages
$ git add .
$ git commit -m"added documentation"
$ git push origin gh-pages
$ git checkout master
```

```ShellSession
$ mkdir artifacts && cd artifacts
$ screencapture -T 10 screenshot.jpg
<Command>-T
$ open https://${GITHUB_USERNAME}.github.io/lab07
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=07
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
```

## Links

- [HTML](https://ru.wikipedia.org/wiki/HTML)
- [LAΤΕΧ](https://ru.wikipedia.org/wiki/LaTeX)
- [man](https://ru.wikipedia.org/wiki/Man_(%D0%BA%D0%BE%D0%BC%D0%B0%D0%BD%D0%B4%D0%B0_Unix))
- [CHM](https://ru.wikipedia.org/wiki/HTMLHelp)
- [PostScript](https://ru.wikipedia.org/wiki/PostScript)

```
Copyright (c) 2017 Братья Вершинины
```
