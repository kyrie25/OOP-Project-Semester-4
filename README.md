# 🛒 Sales & Purchase App – Factory Method Pattern Demo

## 📌 Overview

This project is a simple sales and purchase application built in C++, showcasing the use of the **Factory Method Design Pattern**.

We apply the Factory Method to create:
- Various **Products** (e.g., `Book`, `Electronic`)
- Different **Users** (`Customer`, `Seller`)
- Multiple **Payment Methods**

---

## 🏗️ Project Structure

```
src/
├── payments/
│   ├── PaymentMethod.cpp / .h
│   ├── PaymentMethodFactory.cpp / .h
│
├── products/
│   ├── Product.cpp / .h
│   ├── Book.cpp / .h
│   ├── Electronic.cpp / .h
│   ├── ProductFactory.cpp / .h
│
├── users/
│   ├── User.cpp / .h
│   ├── Customer.cpp / .h
│   ├── Seller.cpp / .h
│   ├── UserFactory.cpp / .h
│
├── ApplicationController.cpp / .h
└── main.cpp
```

---

## 🧠 Design Pattern: Factory Method

### Why Factory Method?

Without Factory Method:
- Classes like `ApplicationController` would be tightly coupled to concrete classes (`Book`, `Seller`, etc.)
- Adding new types would require modifying existing logic

With Factory Method:
- Object creation is delegated to **factory classes**
- Promotes **extensibility** and **loose coupling**

---

### 💡 Example Usage

```cpp
// Using Product Factory
ProductFactory* productFactory = new ProductFactory();
Product* product = productFactory->createProduct("Book");

// Using User Factory
UserFactory* userFactory = new UserFactory();
User* user = userFactory->createUser("Seller");

// Using Payment Method Factory
PaymentMethodFactory* paymentFactory = new PaymentMethodFactory();
PaymentMethod* method = paymentFactory->createPayment("CreditCard");
```

---

## ✅ Benefits

- 🔧 **Easy to Extend**: Add new users/products/payment methods without changing existing core logic
- 🔄 **Reusability**: Shared behavior is reused via base classes/interfaces
- 🧩 **Loose Coupling**: Application code works with abstract types
- 🔐 **Encapsulation**: Object creation details are hidden

---

## 🖥️ Build & Run

```bash
cd src
g++ -std=c++17 *.cpp payments/*.cpp products/*.cpp users/*.cpp -o shop_app
./shop_app
```

---

## 💡 Future Improvements

- Add new product types (`ClothingProduct`, `ServiceProduct`)
- Add user roles (`AdminUser`)
- Integrate payment gateway (Stripe, PayPal)
- Add GUI using Qt or a web-based frontend

---

## 👨‍💻 Contributors

This project was developed by:

- **JakeConal** (Hieu Nguyen)
- **kyrie25** (Nam Anh)
- **emanhthangngot**
