```markdown
# Stock Quote CLI – C++  

A tiny **command-line tool** that fetches **real-time stock quotes** from the **Alpha Vantage API** using **C++**, **libcurl**, and **nlohmann/json**.

---

## Purpose

> **Get the latest price of any stock in one line.**  
> This project is a minimal example of how to call a public REST API, parse JSON, and display clean results – perfect for learning C++ networking or building a personal market watcher.

---

## Features

- One-file core (`main.cpp`)  
- Uses only **header-only** `nlohmann/json`  
- No external dependencies besides **libcurl**  
- Supports any ticker (e.g., `AAPL`, `MSFT`, `PETR4.SA`)  
- Clean output: price, change, % change  

---

## Requirements

| Tool | Install |
|------|---------|
| **g++** (or any C++17 compiler) | `sudo apt install build-essential` |
| **libcurl** | `sudo apt install libcurl4-openssl-dev` |
| **json.hpp** | Download from [nlohmann/json](https://github.com/nlohmann/json/releases) |

---

## How to Build & Run

```bash
# 1. Clone the repo
git clone https://github.com/yourusername/stock-quote-cpp.git
cd stock-quote-cpp

# 2. Compile
g++ -std=c++17 -o stock main.cpp -lcurl

# 3. Run
./stock
```

> **Enter ticker:** `AAPL` →  
> ```
> Price of AAPL:
> Actual Price: US$ 227.55
> Change: -1.45 (-0.63%)
> ```

---

## API Key

1. Get a **free key** at [Alpha Vantage](https://www.alphavantage.co/support/#api-key)  
2. Replace in `main.cpp`:
   ```cpp
   std::string apiKey = "YOUR_API_KEY_HERE";
   ```

> **Tip:** Use environment variable for safety:
> ```bash
> export ALPHA_VANTAGE_KEY="your_key"
> ```
> Then read with `std::getenv("ALPHA_VANTAGE_KEY")`.

---

## Example Output

```text
Enter the ticker that you want see: PETR4.SA

Price of PETR4.SA:
Actual Price: US$ 6.9200
Change: +0.0800 (+1.17%)
```
