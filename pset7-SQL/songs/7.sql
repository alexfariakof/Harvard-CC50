-- sqlite3 songs.db
--.schema
-- cat 7.sql | sqlite3 songs.db
-- check50 cs50/labs/2023/x/songs
-- submit50 cs50/labs/2023/x/songs

/*
    Em 7.sql, escreva uma consulta SQL que retorne a energia média das músicas de Drake.
    Sua consulta deve gerar uma tabela com uma única coluna e uma única linha contendo a energia média.
    Você não deve fazer suposições sobre o que artist_idé Drake.
*/
Select AVG(energy) from songs s inner join artists a on s.artist_id = a.id group by a.name having a.name like 'Drake';