#ifndef INTERPRETTEMP
#define INTERPRETTEMP

// interpreter using template
class Literal
{
public:
    Literal(const double v) : _val(v)
    {}

    double eval() const
    {
        return _val;
    }

private:
    const double _val;
};

class Variable
{
public:
    Variable(double& v) : _val(v)
    {}

    double eval() const
    {
        return _val;
    }

private:
    double& _val;
};

template <typename ExprT>
struct exprTraits
{
    typedef ExprT expr_type;
};

template <>
struct exprTraits < double >
{
    typedef Literal expr_type;
};

template <>
struct exprTraits < int >
{
    typedef Literal expr_type;
};

template <typename ExprT1, typename ExprT2, typename BinOp>
class BinaryExpr
{
public:
    BinaryExpr(ExprT1 e1, ExprT2 e2, BinOp op = BinOp()) :
        _expr1(e1), _expr2(e2), _op(op)
    {}

    double eval() const
    {
        return _op(_expr1.eval(), _expr2.eval());
    }

private:
    typename exprTraits<ExprT1>::expr_type _expr1;
    typename exprTraits<ExprT2>::expr_type _expr2;
    BinOp  _op;
};


template<typename ExprT1, typename ExprT2>
BinaryExpr<ExprT1, ExprT2, std::plus<double>> operator+(ExprT1 e1, ExprT2 e2)
{
    return BinaryExpr<ExprT1, ExprT2, std::plus<double>>(e1, e2);
}

template<typename ExprT1, typename ExprT2>
BinaryExpr<ExprT1, ExprT2, std::multiplies<double>> operator*(ExprT1 e1, ExprT2 e2)
{
    return BinaryExpr<ExprT1, ExprT2, std::multiplies<double>>(e1, e2);
}

template<class Expr>
double eval(const Expr& expr)
{
    return expr.eval();
}


#endif