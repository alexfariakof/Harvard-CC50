-- sqlite3 songs.db
--.schema
-- check50 cs50/labs/2023/x/songs
-- submit50 cs50/labs/2023/x/songs


/*
    Em 3.sql, escreva uma consulta SQL para listar os nomes das 5 músicas mais longas, em ordem decrescente de duração.
        Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada música.
*/

Select name from songs order by duration_ms desc limit 5;