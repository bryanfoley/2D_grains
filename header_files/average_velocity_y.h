double average_velocity_y(double free_particle[n_max][m_max][z_max])
{
       double sumy = 0.0;
       double ans = 0.0;
       
       for(i = 0; i < n_max; i++)
        {
         sumy += free_particle[i][1][0];
        }
       
       ans = (sumy)/n_max;
       
       return(ans);
}
