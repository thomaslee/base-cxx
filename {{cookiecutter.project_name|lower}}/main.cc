#include <iostream>
#include <atomic>
#include <thread>
#include <memory>
#include <chrono>
#include <algorithm>
#include <csignal>

static std::atomic_bool done(false);

static void
worker()
{
    while (!done) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "worker finished" << std::endl;
}

static void
signal_handler (int signum)
{
    if (signum == SIGINT || signum == SIGTERM) {
        done = true;
    }
}

int
main (int argc, char **argv)
{
    std::signal(SIGINT, signal_handler);
    std::signal(SIGTERM, signal_handler);
    std::thread worker_thread(worker);
    worker_thread.join();
    return 0;
}

