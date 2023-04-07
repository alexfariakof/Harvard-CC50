-- sqlite3 songs.db
--.schema
-- check50 cs50/labs/2023/x/songs
-- submit50 cs50/labs/2023/x/songs

/*
   Em 2.sql, escreva uma consulta SQL para listar os nomes de todas as músicas em ordem crescente de tempo.
    Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada música.
*/

Select name from songs order by tempo ASC;
