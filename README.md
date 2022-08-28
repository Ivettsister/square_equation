# Общая информация

Эта программа решает квадратное уравнение с заданными пользователем коэффициентами. 

## Деление программы на файлы с функциями и хедерами

Вся программа поделена на следующие файлы:

+ `main.cpp` (в нём идёт запуск всех последующих функций, обработки ввода, вывода полученных данных);

+ `square_equation.cpp` (в нём находятся основные функции решения квадратного уравнения);

+ `common.cpp` (в нём находятся функции, которые могут использоваться и в других программах в будущем);

+ `unittest.cpp` (в нём находятся функции, необходимые для тестирования программы);

## Работа (запуск) программы

Для запуска программы в режиме тестирования, нужно закомментировать дефайн NDEBUG в самом начале файла `main.cpp`. Далее при вводе `make` в командную строку произойдёт компиляция программы, а при вызове `make run` произойдёт её запуск. Пользователь получит информацию о результате проведённых тестов:

```
$ make run
build/solve_equation
Test 0 is successfully passed
Test 1 is successfully passed
Test 2 is successfully passed
Test 3 is successfully passed
Test 4 is successfully passed
Test 5 is successfully passed
Test 6 is successfully passed
Test 7 is successfully passed
Test 8 is failed
Failed: number of roots = 2, x1 = -1, x2 = 1
Expected: number of roots = 2, x1 = -0.94, x2 = 0.94
Test 9 is successfully passed
Test 10 is successfully passed
Test 11 is successfully passed
```

Для переключения в режим ввода коэффициентов пользователем (ввод проверяется на ошибки), следует раскомментировать дефайн NDEBUG. Далее с помощью тех же шагов скомпилировать и запустить программу. Пользователь получит результат решения своего уравнения:

```
$ make run
build/solve_equation
Let me help you solve your quadratic equation!
To do this, enter its coefficients:
Сoefficient a: 2
Сoefficient b: gn
Please enter the correct coefficient!
5
Сoefficient c: 3
Your equation has two roots: x1 = -1.50, x2 = -1.00
```

## Ввод данных

Ввод коэффициентов в режиме взаимодействия пользователя с программой представляет собой последовательнон введение коэффициентов, сразу проходящих проверку на ошибку, в случае неверного представления коэффициента пользователю потребуется повторить ввод конкретного коэффициента:

```
Сoefficient a: 2
Сoefficient b: gn
Please enter the correct coefficient!
5
Сoefficient c: 3
```

### Результат выполнения программы

Результат выполнения программы представляет собой строку с информацией о количестве корней заданного пользователем уравнения и самих корнях:

```
Your equation has two roots: x1 = -1.50, x2 = -1.00
```
