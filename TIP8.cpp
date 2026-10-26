#include <iostream>

using namespace std;

// Функция быстрого возведения в степень
// base - основание (цена, например), exp - степень (на сколько умножаем)
long long fastPow(long long base, long long exp) {
    long long result = 1; // Здесь будет наш ответ
    
    // Пока степень больше 0, продолжаем
    while (exp > 0) {
        // Если текущая степень нечётная (последний бит 1),
        // значит, нам нужно умножить результат на текущее основание
        if (exp % 2 == 1) {
            result *= base;
        }
        
        // Теперь готовим основание для следующего шага:
        // возводим его в квадрат (a -> a^2 -> a^4 -> a^8...)
        base *= base;
        
        // Делим степень на 2 (отбрасываем последний бит)
        exp /= 2;
    }
    
    return result;
}

int main() {
    // Пример для застройщиков: базовая цена и множитель
    long long price = 10;
    long long multiplier = 12;

    long long finalPrice = fastPow(price, multiplier);

    cout << "Базовая цена: " << price << endl;
    cout << "Степень (множитель): " << multiplier << endl;
    cout << "Итоговая цена: " << finalPrice << endl;

    return 0;
}
//2 
#include <iostream>

// Рекурсивный НОД по Евклиду через остаток.
// Работает для натуральных a, b (и для a, b >= 0).
long long gcd(long long a, long long b) {
    if (b == 0) return a;      // база рекурсии
    return gcd(b, a % b);      // рекурсивный шаг
}

int main() {
    long long a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b) << "\n";
    return 0;
}
#include <iostream>

// Рекурсивный НОД алгоритмом Евклида через вычитание.
// Работает для натуральных a, b.
long long gcdSubtract(long long a, long long b) {
    if (a == b) return a;              // база рекурсии
    if (a > b)  return gcdSubtract(a - b, b);
    else        return gcdSubtract(a, b - a);
}

int main() {
    long long a, b;
    std::cin >> a >> b;
    std::cout << gcdSubtract(a, b) << "\n";
    return 0;
}
//3
#include <iostream>

// Переносим n ингредиентов со стержня from на стержень to,
// используя aux как вспомогательный.
// Ингредиенты нумеруются от 1 (самый маленький) до n (самый большой).
void hanoi(int n, int from, int to, int aux) {
    if (n == 0) return;                       // база рекурсии

    hanoi(n - 1, from, aux, to);              // 1) n-1 верхних — на aux
    std::cout << "Ingredient " << n
              << " move from " << from
              << " to " << to << "\n";        // 2) самый большой — на to
    hanoi(n - 1, aux, to, from);              // 3) n-1 с aux — на to
}

int main() {
    int n;
    std::cin >> n;
    hanoi(n, 1, 3, 2);                        // с 1-й салфетки на 3-ю, через 2-ю
    return 0;
}