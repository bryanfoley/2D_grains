void reset_velocities(double free_particle[n_max][m_max][z_max], 
                        double image_free_particle[n_max][m_max][z_max])
{
       int i,l;
       
       for(i = 0; i < n_max; i++)
        {
         for(l = 0; l < z_max; l++)
          {
           free_particle[i][0][l] = 0.0;
           free_particle[i][1][l] = 0.0;
           image_free_particle[i][0][l] = 0.0;
           image_free_particle[i][1][l] = 0.0;
          }
        }
}
