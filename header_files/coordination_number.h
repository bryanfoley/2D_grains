double coordination_number(double free_particle[n_max][m_max][z_max])
{
       double sum = 0.0;
       double ans;
       int i,j,k;
       
       for(i = 0; i < n_max; i++)
       {
        sum += free_particle[i][10][0];
       }
       
       ans = ((sum/n_max));
       
       return(ans);
}
