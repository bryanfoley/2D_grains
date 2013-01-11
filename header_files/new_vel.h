void new_vel(double free_particle[n_max][m_max][z_max],
             double image_free_particle[n_max][m_max][z_max])
{
     int i;
     
     for(i = 0; i < n_max; i++)
      {
       free_particle[i][0][1] = free_particle[i][0][0]
                           +(((free_particle[i][4][0] + free_particle[i][4][1])/2.0000000000000000)*(dt));
       free_particle[i][1][1] = free_particle[i][1][0]
                           +(((free_particle[i][5][0] + free_particle[i][5][1])/2.0000000000000000)*(dt));
                           
       image_free_particle[i][0][1] = image_free_particle[i][0][0]
                           +(((image_free_particle[i][4][0] + image_free_particle[i][4][1])/2.0000000000000000)*(dt));
       image_free_particle[i][1][1] = image_free_particle[i][1][0]
                           +(((image_free_particle[i][5][0] + image_free_particle[i][5][1])/2.0000000000000000)*(dt));
      }
}
