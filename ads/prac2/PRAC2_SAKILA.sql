use sakila;
# ===== Querying Films by Rating ================================================ #
SELECT film_id, title, rating
FROM film
WHERE rating = 'PG-13';

EXPLAIN SELECT film_id, title, rating
FROM film
WHERE rating = 'PG-13';

CREATE INDEX idx_rating ON film(rating);

SELECT film_id, title, rating
FROM film
WHERE rating = 'PG-13';

EXPLAIN SELECT film_id, title, rating
FROM film
WHERE rating = 'PG-13';

DROP INDEX idx_rating ON film;

# =============================================================================== #


# ===== Querying Payment Amount by Customer ID and Payment Date # =============== #
SELECT payment_id, amount, payment_date
FROM payment
WHERE customer_id = 50 AND payment_date = '2005-05-25 11:30:37';

EXPLAIN SELECT payment_id, amount, payment_date
FROM payment
WHERE customer_id = 50 AND payment_date = '2005-05-25 11:30:37';

CREATE INDEX idx_customer_paymentdate ON payment(customer_id, payment_date);

SELECT payment_id, amount, payment_date
FROM payment
WHERE customer_id = 50 AND payment_date = '2005-05-25 11:30:37';

EXPLAIN SELECT payment_id, amount, payment_date
FROM payment
WHERE customer_id = 50 AND payment_date = '2005-05-25 11:30:37';

DROP INDEX idx_customer_paymentdate ON payment;
# ================================================================================ #

# =========== Search for actors whose name includes a particular substring ======= #
SELECT actor_id, first_name, last_name
FROM actor
WHERE last_name LIKE '%Smith%';

EXPLAIN SELECT actor_id, first_name, last_name
FROM actor
WHERE last_name LIKE '%Smith%';

CREATE FULLTEXT INDEX idx_actor_name ON actor(last_name);

SELECT actor_id, first_name, last_name
FROM actor
WHERE MATCH(last_name) AGAINST('Smith');

EXPLAIN SELECT actor_id, first_name, last_name
FROM actor
WHERE MATCH(last_name) AGAINST('Smith');

DROP INDEX idx_actor_name ON actor;

# ================================================================================ #

# Select a specific rental by rental_id (Primary Key)
ALTER TABLE payment DROP PRIMARY KEY;
# desc rental;
SELECT * FROM actor WHERE actor_id = 3;