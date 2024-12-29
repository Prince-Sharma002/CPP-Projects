#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

const int WIDTH = 20;
const int HEIGHT = 15;

class Spaceship {
public:
    int x;
    Spaceship() : x(WIDTH / 2) {}
    void moveLeft() { if (x > 0) x--; }
    void moveRight() { if (x < WIDTH - 1) x++; }
};

class Asteroid {
public:
    int x, y;
    Asteroid() : x(rand() % WIDTH), y(0) {}
    void fall() { y++; }
};

class Game {
private:
    Spaceship ship;
    std::vector<Asteroid> asteroids;
    int score;
    bool gameOver;

public:
    Game() : score(0), gameOver(false) {
        srand(static_cast<unsigned>(time(0)));
    }

    void run() {
        while (!gameOver) {
            input();
            update();
            render();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        std::cout << "Game Over! Your score: " << score << std::endl;
    }

private:
    void input() {
        if (std::cin.peek() != EOF) {
            char ch = std::cin.get();
            if (ch == 'a') ship.moveLeft();
            if (ch == 'd') ship.moveRight();
        }
    }

    void update() {
        if (rand() % 5 == 0) asteroids.push_back(Asteroid());
        
        for (auto& asteroid : asteroids) {
            asteroid.fall();
        }

        asteroids.erase(
            std::remove_if(asteroids.begin(), asteroids.end(),
                [this](const Asteroid& a) {
                    if (a.y >= HEIGHT) {
                        score++;
                        return true;
                    }
                    return false;
                }
            ),
            asteroids.end()
        );

        for (const auto& asteroid : asteroids) {
            if (asteroid.x == ship.x && asteroid.y == HEIGHT - 1) {
                gameOver = true;
                break;
            }
        }
    }

    void render() {
        std::vector<std::string> screen(HEIGHT, std::string(WIDTH, ' '));

        for (const auto& asteroid : asteroids) {
            if (asteroid.y < HEIGHT) screen[asteroid.y][asteroid.x] = '*';
        }

        screen[HEIGHT - 1][ship.x] = '^';

        system("clear");  // Use "cls" instead of "clear" on Windows
        for (const auto& row : screen) {
            std::cout << row << std::endl;
        }
        std::cout << "Score: " << score << std::endl;
    }
};

int main() {
    Game game;
    game.run();
    return 0;
}