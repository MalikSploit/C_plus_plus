//
// Created by root on 12/20/23.
//

#ifndef C_FORME_HPP
#define C_FORME_HPP

class Forme {
public:
    [[nodiscard]] virtual Forme* clone() const = 0;
};

#endif //C_FORME_HPP
