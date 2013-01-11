double average_velocity_x(double free_particle[n_max][m_max][z_max])
{
       double sumx = 0.0;
       double ans = 0.0;
       
       for(i = 0; i < n_max; i++)
        {
         sumx += free_particle[i][0][0];
        }
       
       ans = (sumx)/n_max;
       
       return(ans);
}
