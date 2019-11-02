#include "Gradient_descent_R.hpp"

bool Gradient_descent_R::converged(const unsigned num_iter, const real x, const real incr, const stop_criteria ST) const
{
    if (max_iter < num_iter)
    {
        cout<<"Maximum iterations number reached"<<endl;
        return true;
    }

    switch (ST) // ST is the stopping criteria
    {
    case RESIDUAL:
        return fabs(f.diff().eval(x)) < tol;
        break;

    case INCREMENT:
        return fabs(incr) < tol;
        break;

    case BOTH:
        return fabs(f.diff().eval(x)) < tol && fabs(incr) < tol;
        break;
    }
}

real Gradient_descent_R::get_min(real x_old) const
{
    real incr = 1e20;
    unsigned int long num_iter = 0;
    real x_new;
    real m; // df(x_old)
    while (!converged(num_iter, x_old, incr, ST))
    {
        m = f.diff().eval(x_old);
        x_new = x_old - m * step;
        incr = f.eval(x_new) - f.eval(x_old);
        x_old = x_new;
        num_iter++;
    }
    return x_new;
}
real Gradient_descent_R::get_min_multistart(int num_starting_points) const
{
    real x_old;
    real x_new;
    real x_min = 1.7e308;
    std::default_random_engine generator;
    std::uniform_real_distribution<real> distribution (lb,ub);
   
    for (int k = 0; k < num_starting_points; ++k)
    {
        x_old= distribution(generator);
        x_new = get_min(x_old);
        if (f.eval(x_new) < f.eval(x_min))
            x_min = x_new;
    }
    return x_min;
}

real Gradient_descent_R::get_min_dom_decomposition(int num_intervals) const
{
    real subint_len = (ub - lb) / ((real)num_intervals); // length of each subinterval
    real x_old;
    real x_new;
    real x_min = 1.7e308;
    for (int k = 0; k < num_intervals; ++k)
    {   
        x_old = lb + k * subint_len + subint_len / 2; //take the middle point of each subinterval as starting point
        x_new = get_min(x_old);
        cout<<"Starting from: "<<x_old<<endl;
        if (f.eval(x_new) < f.eval(x_min))
            x_min = x_new;
    }
    return x_min;
}