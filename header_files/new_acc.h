void new_acc(double free_particle[n_max][m_max][z_max],
             double image_free_particle[n_max][m_max][z_max])
{
     int i;
     char func_name[30] = "new_acc";
     char action_begin[10] = ">>>";
     char action_end[10] = "<<<";
     time_stamp();
     trace(func_name,action_begin);
     
     for(i=0; i<(n_max); i++)
      {
       /*Acceleration of free_particle 'i', x component*/
       free_particle[i][4][1] = ((free_particle[i][6][0])/(free_particle[i][8][0]));
       /*Acceleration of free_particle 'i', y component*/
       free_particle[i][5][1] = ((free_particle[i][7][0])/(free_particle[i][8][0]));
       
       /*Acceleration of image_free_particle 'i', x component*/
       image_free_particle[i][4][1] = ((image_free_particle[i][6][0])/(image_free_particle[i][8][0]));
       /*Acceleration of image_free_particle 'i', y component*/
       image_free_particle[i][5][1] = ((image_free_particle[i][7][0])/(image_free_particle[i][8][0]));
      }
    time_stamp();
    trace(func_name,action_end);
}
