rm(list = ls())

sequencial = c(5.180860, 5.167948, 5.185700, 5.172843, 5.172104, 5.145790, 5.276064, 5.165855, 5.514360, 5.653333)
mover_frente = c(8.069880, 9.749980, 8.127777, 8.036540, 8.169432, 8.026311, 8.076840, 8.107727, 8.150506, 8.089942)
transposicao = c(5.161405, 5.157480, 5.137197, 5.167922, 5.160152, 5.177794, 5.169555, 5.187828, 5.202987, 5.159522)
indice = c(0.898166, 0.907286, 0.898850, 0.904969, 0.905977, 0.907317, 0.906211, 0.904533, 0.907852, 0.902294)

media_sequencial = mean(sequencial)
dp_sequencial = sd(sequencial)

media_mover_frente = mean(mover_frente)
dp_mover_frente = sd(mover_frente)

media_transposicao = mean(transposicao)
dp_transposicao = sd(transposicao)

media_indice = mean(indice)
dp_indice = sd(indice)

metodos = c("Sequencial", "Mover para frente", "Transposição", "Índice Primário")
medias = c(media_sequencial, media_mover_frente, media_transposicao, media_indice)
dp = c(dp_sequencial, dp_mover_frente, dp_transposicao, dp_indice)

bar = barplot(medias, main = "Tempos de execução", names.arg = metodos, xlab = "Métodos", ylab = "Médias", ylim = c(0, 9))
arrows(bar, medias+dp, bar, medias-dp, length = 0.1, angle = 90, code = 3)
