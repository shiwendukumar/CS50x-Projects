SELECT movies.title FROM stars
JOIN movies ON movies.id = stars.movie_id
JOIN ratings ON ratings.movie_id = movies.id
WHERE stars.person_id = (SELECT id FROM people WHERE name = "Chadwick Boseman")
ORDER BY ratings.rating DESC LIMIT 5;