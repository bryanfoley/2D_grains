void old_acc(double free_particle[n_max][m_max][z_max],
             double image_free_particle[n_max][m_max][z_max])
{
     int i;
     char func_name[30] = "old_acc";
     char action_begin[10] = ">>>";
     char action_end[10] = "<<<";
     time_stamp();
     trace(func_name,action_begin);
     
     /*Calculate the acceleration of the free_particles and image_free_particles*/
     for(i=0; i<(n_max); i++)
      {
       /*Acceleration of free_particle 'i', x component*/
       free_particle[i][4][0] = ((free_particle[i][6][0])/(free_particle[i][8][0]));
       /*Acceleration of free_particle 'i', y component*/
       free_particle[i][5][0] = ((free_particle[i][7][0])/(free_particle[i][8][0]));
       
       /*Acceleration of image_free_particle 'i', x component*/
       image_free_particle[i][4][0] = ((image_free_particle[i][6][0])/(image_free_particle[i][8][0]));
       /*Acceleration of image_free_particle 'i', y component*/
       image_free_particle[i][5][0] = ((image_free_particle[i][7][0])/(image_free_particle[i][8][0]));
      }
     time_stamp();
     trace(func_name,action_end);
}
