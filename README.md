# Общая информация

Эта программа решает квадратное уравнение с заданными пользователем коэффициентами. 

## Деление программы на файлы с функциями и хедерами

Вся программа поделена на основной файл запуска `main.cpp`, из которого идут ссылки на cледйщие файлы:

+ `square_equation.cpp` (там находятся основные функции решения квадратного уравнения);

+ `common.cpp` (там находятся функции, которые могут использоваться и в других программах в будущем)ж

+ `unittest.cpp` (там находятся функции, необходимые для тестирования программы);

## Работа самой программы

Ввод данных (коэффициентов уравнения) осуществляется последовательно, проходит проверку на ошибки (коэффициенты должны быть целыми числами). Далее коэффициенты передаются в функцию `solve_square`, где в случае нулевого коэффициента a передаются в функцию `solve_linear` решения линейного уравнения, либо проходят через операцию вычисления дикриминанта и заполнения структуры с информацией об этих корнях (их количестве) и самими корнями.

Вывод данных - программа выводит строку с информацией о количестве корней уравнения и саимими корнями (при их наличии).

## Тестирование программы

Тестирование реализовано с помощью заполнения массива структурами, каждыя из которых представляет собой содержимое из двух структур, в первой из которых лежат коэффиценты, передаваемые программе, а во второй - правильные ответы. 

```В прграмме создаётся структура, идентичная по строению  структуре, хранящей информацию о решении уравнения, котрая последовательно сравнивается с заведомо правильной структурой, используя сравнения чисел с определённой точностью (данная функция лежит в файле common.cpp).```

После каждого теста пользователь получает обратную связь об успешном или нет выполнении теста (в случае последнего пользователь получит информацию, о том, что именно является не верным в исполнении теста).

### Переключение программы из режима тестирования в режим взаимодействия с пользователем

Такой переход осуществляется с помощью дефайна NDEBUG в главном файле `main.cpp`.
