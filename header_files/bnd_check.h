void bnd_check (double free_particle[n_max][m_max][z_max],double wall_particle[44][m_max][z_max])
{
      int i;
      char func_name[30] = "bnd_check";
      char action_begin[10] = ">>>";
      char action_end[10] = "<<<";
      time_stamp();
      trace(func_name,action_begin);
/*____________________________________________________________________________*/      
      /*Cycle through all free_partcles*/
      for(i = 0; i < n_max; i++)
       {
        /*Check if the free_particle has gone out of bounds on the left*/
         if((((free_particle[i][2][0] + free_particle[i][9][0]) < 0.0) && (free_particle[i][0][0] <= 0.0)) || (((free_particle[i][2][1] + free_particle[i][9][0]) < 0.0) && (free_particle[i][0][1] <= 0.0)))
         {
          /*Check if the free_particle has gone out of bounds on the left*/
          /*If the particle is out of bounds on the left*/
          /*Change the 16th parameter to 3.0            */
          free_particle[i][16][0] = 3.0;
         }
         else if((((free_particle[i][2][0] - free_particle[i][9][0]) > 10.0) && (free_particle[i][0][0] >= 0.0)) || (((free_particle[i][2][1] - free_particle[i][9][0]) > 10.0) && (free_particle[i][0][1] >= 0.0)))
         {
          /*Check if the free_particle has gone out of bounds on the right*/
          /*If the particle is out of bounds on the right*/
          /*Change the 16th parameter to 4.0             */
          free_particle[i][16][0] = 4.0;
         }
         else if((((free_particle[i][2][0] - free_particle[i][9][0]) < 0.0) && (free_particle[i][0][0] <= 0.0)) || (((free_particle[i][2][1] - free_particle[i][9][0]) < 0.0) && (free_particle[i][0][1] <= 0.0)))
         {
          /*If the particle is about to go out of bounds on the left*/
          /*change the 16th parameter to 1.0                        */
          free_particle[i][16][0] = 1.0;
         }
         else if((((free_particle[i][2][0]+free_particle[i][9][0]) > 10.0) && (free_particle[i][0][0] >= 0.0)) || (((free_particle[i][2][1]+free_particle[i][9][0]) > 10.0) && (free_particle[i][0][1] >= 0.0)))
         {
          /*Check if the free_particle is about to go out of bounds on the right*/
          /*If the particle is about to go out of bounds on the right*/
          /*change the 16th parameter to 2.0                        */
          free_particle[i][16][0] = 2.0;
         }
        else
         {
          free_particle[i][16][0] = 0.0;
         } 
       }
    /**************************************************************************/   
       /*Cycle through all image_free_partcles*/
      for(i = 0; i < n_max; i++)
       {
        /*Check if the image_free_particle has gone out of bounds on the left*/
         if((((image_free_particle[i][2][0] + image_free_particle[i][9][0]) < 0.0) && (image_free_particle[i][0][0] <= 0.0)) || (((image_free_particle[i][2][1] + image_free_particle[i][9][0]) < 0.0) && (image_free_particle[i][0][1] <= 0.0)))
         {
          /*Check if the image_free_particle has gone out of bounds on the left*/
          /*If the particle is out of bounds on the left*/
          /*Change the 16th parameter to 3.0            */
          image_free_particle[i][16][0] = 3.0;
         }
         else if((((image_free_particle[i][2][0] - image_free_particle[i][9][0]) > 10.0) && (image_free_particle[i][0][0] >= 0.0)) || (((image_free_particle[i][2][1] - image_free_particle[i][9][0]) > 10.0) && (image_free_particle[i][0][1] >= 0.0)))
         {
          /*Check if the image_free_particle has gone out of bounds on the right*/
          /*If the particle is out of bounds on the right*/
          /*Change the 16th parameter to 4.0             */
          image_free_particle[i][16][0] = 4.0;
         }
         else if((((image_free_particle[i][2][0] - image_free_particle[i][9][0]) < 0.0) && (image_free_particle[i][0][0] <= 0.0)) || (((image_free_particle[i][2][1] - image_free_particle[i][9][0]) < 0.0) && (image_free_particle[i][0][1] <= 0.0)))
         {
          /*If the particle is about to go out of bounds on the left*/
          /*change the 16th parameter to 1.0                        */
          image_free_particle[i][16][0] = 1.0;
         }
         else if((((image_free_particle[i][2][0]+image_free_particle[i][9][0]) > 10.0) && (image_free_particle[i][0][0] >= 0.0)) || (((image_free_particle[i][2][1]+image_free_particle[i][9][0]) > 10.0) && (image_free_particle[i][0][1] >= 0.0)))
         {
          /*Check if the image_free_particle is about to go out of bounds on the right*/
          /*If the particle is about to go out of bounds on the right*/
          /*change the 16th parameter to 2.0                        */
          image_free_particle[i][16][0] = 2.0;
         }
        else
         {
          image_free_particle[i][16][0] = 0.0;
         } 
       }
/*____________________________________________________________________________*/       
       /*Cycle through the wall_particles*/
       for(i = 22; i < 44; i++)
        {
          /*Reset the 16th parameter of each particle*/
          wall_particle[i][16][0] = 0.0;
          
          /*Check if the wall_particle has gone out of bounds on the right*/
          if((wall_particle[i][2][0] - wall_particle[i][9][0]) > 16.0)
           {
            wall_particle[i][16][0] = 1.0;
           }  
        }
    time_stamp();
    trace(func_name,action_end); 
}
