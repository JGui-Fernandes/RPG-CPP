enum TipoItem{
    C,
    R,
    W"
};

char* tipoArmaParaString(TipoArma tipo) {
    switch (tipo) {
        case TipoArma::C: return "Comum";
        case TipoArma::R: return "Armadura";
        case TipoArma::W: return "Arma";
        default: return "Desconhecido";
    }
}
