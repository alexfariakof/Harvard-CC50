-- Keep a log of any SQL queries you execute as you solve the mystery.

--https://ead.napratica.org.br/enrollments/7324870/courses/84414/course_contents/2177138
-- Keep a log of any SQL queries you execute as you solve the mystery.

-- sqlite3 fiftyville.db
-- .schema
-- cat log.sql | sqlite3 fiftyville.db
-- check50 cs50/problems/2021/x/fiftyville
-- submit50 cs50/problems/2023/x/fiftyville

/*
O Pato CS50 foi roubado! A cidade de Fiftyville chamou você para resolver o mistério do pato roubado. As autoridades acreditam que o ladrão roubou o pato e,
 pouco depois, embarcou para fora da cidade com a ajuda de um cúmplice. Seu objetivo é identificar:

Quem é o ladrão,
Para qual cidade o ladrão fugiu, e
Quem é o cúmplice do ladrão que os ajudou a escapar
Tudo o que você sabe é que o roubo ocorreu em 28 de julho de 2021 e ocorreu na Humphrey Street .

Como você vai resolver esse mistério? As autoridades de Fiftyville pegaram alguns dos registros da cidade na época do roubo e prepararam um banco de dados
SQLite para você, fiftyville.dbque contém tabelas de dados de toda a cidade. Você pode consultar essa tabela usando
SELECTconsultas SQL para acessar os dados de seu interesse. Usando apenas as informações do banco de dados, sua tarefa é resolver o mistério.
*/



-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Obtendo descrições dos crimes que aconteceram em 28 de julho de 2020 na Rua Chamberlin.
SELECT description FROM crime_scene_reports WHERE day = "28" AND month = "7" AND year = "2020" AND street = "Chamberlin Street";

-- Verificando a transcrição das entrevistas da data do roubo mencionadas pelo tribunal.
SELECT transcript FROM interviews WHERE day = "28" AND month = "7" AND year = "2020" AND transcript like "%courthouse%";

-- Com base na transcrição da primeira entrevista: Encontrar os nomes das pessoas que saíram do tribunal 10 minutos após o roubo.
SELECT name FROM people JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate WHERE day = "28" AND month = "7" AND year = "2020" AND hour = "10" AND minute >= "15" AND minute < "25" AND activity = "exit";

-- Com base na transcrição da segunda entrevista: Encontrar os nomes das pessoas que sacaram dinheiro no caixa eletrônico na Rua Fifer no dia do roubo.
SELECT DISTINCT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number WHERE day = "28" AND month = "7" AND year = "2020" AND transaction_type = "withdraw" AND atm_location = "Fifer Street";

-- Com base na transcrição da terceira entrevista: Encontrar os nomes das pessoas que compraram a primeira passagem de avião para o dia seguinte ao roubo.
SELECT name FROM people JOIN passengers ON people.passport_number = passengers.passport_number WHERE flight_id = (SELECT id FROM flights WHERE day = "29" AND month = "7" AND year = "2020" ORDER BY hour,minute LIMIT 1);

-- Com base na transcrição da terceira entrevista: Encontrar os nomes das pessoas que fizeram uma ligação de menos de um minuto no dia do roubo.
SELECT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.caller WHERE day = "28" AND month = "7" AND year = "2020" AND duration < "60";

--Os requisitos para encontrar o ladrão foram cumpridos.
SELECT name FROM people JOIN passengers ON people.passport_number = passengers.passport_number WHERE flight_id = (SELECT id FROM flights WHERE day = "29" AND month = "7" AND year = "2020" ORDER By hour, minute LIMIT 1) INTERSECT SELECT DISTINCT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number WHERE day = "28" AND month = "7" AND year = "2020" AND transaction_type = "withdraw" AND atm_location = "Fifer Street" INTERSECT SELECT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.caller WHERE day = "28" AND month = "7" AND year = "2020" AND duration < "60" INTERSECT SELECT name FROM people JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate WHERE day = "28" AND month = "7" AND year = "2020" AND hour = "10" AND minute >= "15" AND minute < "25" AND activity = "exit";

-- Com base na transcrição da terceira entrevista: Encontrar o destino da primeira passagem de avião para o dia seguinte ao roubo.
SELECT city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE day = "29" AND month = "7" AND year = "2020" ORDER BY hour,minute LIMIT 1);

-- Com base na transcrição da terceira entrevista: Encontrar o nome da pessoa que o ladrão ligou por menos de um minuto no dia do roubo.
SELECT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.receiver WHERE day = "28" AND month = "7" AND year = "2020" AND duration < "60" AND caller = (SELECT phone_number FROM people WHERE name = "Ernest");

-- O ladrão é Ernest, ele ESCAPOU para Londres com a ajuda de Berthold.