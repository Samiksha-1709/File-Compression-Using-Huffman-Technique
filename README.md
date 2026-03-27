# 📦 Huffman File Compression Tool (C Language)

## 📖 Overview

This project is a **File Compression and Decompression Tool** implemented in **C language** using the **Huffman Coding algorithm**.
It is a **lossless compression technique**, meaning the original data can be perfectly reconstructed after decompression.

The tool compresses `.txt` files into a `.huf` format and decompresses them back to their original form.

---

## 🚀 Features

* 📉 Compress `.txt` files into `.huf`
* 🔄 Decompress `.huf` files back to `.txt`
* ⚡ Efficient **bit-level encoding**
* 🌳 Uses **Huffman Tree & Min Heap**
* 💯 **Lossless compression (no data loss)**
* 🖥️ Simple and clean **command-line interface**

---

## 🛠️ Technologies Used

* **Language:** C
* **Concepts:**

  * Huffman Coding
  * Binary Trees
  * Min Heap (Priority Queue)
  * File Handling
  * Bit Manipulation

---

## 📂 Project Structure

```
.
├── main.c
├── main.h
├── compress.c
├── compress.h
├── decompress.c
├── decompress.h
├── huffman.c
├── huffman.h
├── heap.c
├── heap.h
└── README.md
```

---

## ⚙️ How It Works

### 🔹 Compression

```
input.txt
   ↓
Calculate Frequency
   ↓
Build Huffman Tree
   ↓
Generate Codes
   ↓
Encode Data
   ↓
output.huf
```

### 🔹 Decompression

```
output.huf
   ↓
Read Header
   ↓
Rebuild Huffman Tree
   ↓
Decode Data
   ↓
recovered.txt
```

---

## ▶️ How to Run

### 1️⃣ Compile

```bash
gcc *.c -o huffman
```

### 2️⃣ Compress a File

```bash
./huffman -c input.txt output.huf
```

### 3️⃣ Decompress a File

```bash
./huffman -d output.huf recovered.txt
```

---

## ✅ Example

```bash
./huffman -c sample.txt sample.huf
./huffman -d sample.huf output.txt
```

Verify:

```bash
diff sample.txt output.txt
```

---

## 📊 Output Example

```
====================================
        HUFFMAN COMPRESSION
====================================
[STEP 1] Calculating Frequencies
[STEP 2] Building Huffman Tree
[STEP 3] Generating Codes
[STEP 4] Writing Header
[STEP 5] Encoding Data
====================================
   COMPRESSION COMPLETED SUCCESSFULLY
====================================
```

---

## 🎯 Objectives

* Implement **Huffman Coding algorithm**
* Reduce file size efficiently
* Understand **trees, heaps, and bit manipulation**
* Build a complete **compression-decompression system**

---

## 📌 Limitations

* Supports only `.txt` files
* Compression efficiency depends on input data
* Already compressed files (like `.pdf`, `.jpg`) may not reduce in size

---

## 🌟 Future Improvements

* Support multiple file formats
* Improve header compression
* Add GUI interface
* Implement advanced compression techniques

---

## 👩‍💻 Author

**Samiksha Mane**
B.Tech Electronics & Telecommunication Engineering

---


