# CPL Generator

A Python utility for generating a structured PDF document from your C++ competitive programming library.

## Project Structure

Place the `cpl-generator` directory at the root of your competitive programming repository. The script will recursively scan the parent directory to locate and include all `.cpp` files.

```text
your-competitive-programming-library/
├── math/
│   ├── gcd.cpp
│   └── sieve.cpp
├── graphs/
│   ├── dijkstra.cpp
│   └── dfs.cpp
└── cpl-generator/          <-- Drop the generator here
    ├── generator.py
    ├── requirements.txt
    ├── icon.png            <-- Your team logo
    └── library.pdf         <-- Example output file
```

## Setup and Installation

**1. Navigate to the generator directory:**
```bash
cd your-competitive-programming-library/cpl-generator
```

**2. Create and activate a virtual environment:**
```bash
python3 -m venv env
source env/bin/activate
```

**3. Install dependencies:**
```bash
pip install -r requirements.txt
```

## Configuration

Open `generator.py` and update the `user_info` dictionary at the bottom of the script with your personal details:

```python
if __name__ == '__main__':
    lib_data = scan_library_files()
    if lib_data:
        user_info = {
            'name': 'YOUR NAME',        
            'team': 'YOUR TEAM',
            'icon_path': 'icon.png'     # Set to None if you do not have a logo
        }
        generate_pdf(lib_data, user_info)
```

## Usage

An example of the final output is already included in the folder as `library.pdf`. 

To generate a new PDF with your updated code, execute the script from within the `cpl-generator` directory:

```bash
python3 generator.py
```

The output file `library.pdf` will be overwritten or generated in the current directory.

## Credits

AI Assistance: Google Gemini
