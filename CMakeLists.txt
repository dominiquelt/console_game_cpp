# 1. Określamy minimalną wymaganą wersję CMake
cmake_minimum_required(VERSION 3.10)

# 2. Nadajemy nazwę naszemu projektowi
project(ex0)

# 3. Ustawiamy standard C++ (najlepiej C++17 lub nowszy, żeby używać nowoczesnych funkcji)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 4. Tworzymy plik wykonywalny (aplikację) o nazwie "app"
# Ważne: Wymieniamy tu TYLKO pliki źródłowe (.cc lub .cpp). 
# Plików nagłówkowych (.h) tu nie wpisujemy, kompilator sam je znajdzie!
add_executable(app main.cc def.cc)