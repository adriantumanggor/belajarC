-- Create the 'categories' table
CREATE TABLE IF NOT EXISTS categories (
  id INT PRIMARY KEY AUTO_INCREMENT,
  name VARCHAR(255) NOT NULL UNIQUE
);

-- Create the 'transactions' table
CREATE TABLE IF NOT EXISTS transactions (
  id INT PRIMARY KEY AUTO_INCREMENT,
  date DATE NOT NULL,
  amount DECIMAL(10,2) NOT NULL,
  category_id INT NOT NULL,
  FOREIGN KEY (category_id) REFERENCES categories(id)
);

-- (Optional) Create the 'descriptions' table (if you want to store descriptions separately)
CREATE TABLE IF NOT EXISTS descriptions (
  id INT PRIMARY KEY AUTO_INCREMENT,
  transaction_id INT NOT NULL,
  text TEXT,
  FOREIGN KEY (transaction_id) REFERENCES transactions(id)
);

-- (Optional) Populate initial categories (replace with your desired categories)
INSERT INTO categories (name) VALUES ('Breakfast'), ('Lunch'), ('Dinner');
