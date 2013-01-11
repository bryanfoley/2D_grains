double kinetic (double free_particle[n_max][m_max][z_max])
{
     int i;
     double sum_kinetic = 0.0000000000000000;
     
     for(i = 0; i < n_max; i++)
      {
       sum_kinetic += (((free_particle[i][8][0])/2.0000000000000000)*((pow((free_particle[i][0][1]),2.0000000000000000))
                  +(pow((free_particle[i][1][1]),2.0000000000000000))));
      }
     return(sum_kinetic);
}
