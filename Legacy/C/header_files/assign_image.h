void assign_image(double free_particle[n_max][m_max][z_max],
                  double image_free_particle[n_max][m_max][z_max],
                  double wall_particle[44][m_max][z_max])
{
      int i;
      char func_name[15] = "assign_image";
      char action_begin[10] = ">>>";
      char action_end[10] = "<<<";
      time_stamp();
      trace(func_name,action_begin);
/*____________________________________________________________________________*/      
      /*Cycle through all free_particles*/
      for(i = 0; i < n_max; i++)
       {
        /*If a particle is about to go out of bounds on the left*/
        if(free_particle[i][16][0] == 1.0)
         {
          /*Assign an image, that is 10.0 distance units to the right*/
          image_free_particle[i][2][0] = (free_particle[i][2][0] + 10.0);
          image_free_particle[i][2][1] = (free_particle[i][2][1] + 10.0);
          /*And has the same y position*/
          image_free_particle[i][3][0] = free_particle[i][3][0];
          image_free_particle[i][3][1] = free_particle[i][3][1];
          /*And has the same x and y velocity components*/
          image_free_particle[i][0][0] = free_particle[i][0][0];
          image_free_particle[i][1][0] = free_particle[i][1][0];
          image_free_particle[i][0][1] = free_particle[i][0][1];
          image_free_particle[i][1][1] = free_particle[i][1][1];         
         }
         
        /*If a particle is about to go out of bounds on the right*/ 
        if(free_particle[i][16][0] == 2.0)
         {
          /*Assign an image, that is 10.0 distance units to the left*/
          image_free_particle[i][2][0] = (free_particle[i][2][0] - 10.0);
          image_free_particle[i][2][1] = (free_particle[i][2][1] - 10.0);
          /*And has the same y position*/
          image_free_particle[i][3][0] = free_particle[i][3][0];
          image_free_particle[i][3][1] = free_particle[i][3][1];
          /*And has the same x and y velocity components*/
          image_free_particle[i][0][0] = free_particle[i][0][0];
          image_free_particle[i][1][0] = free_particle[i][1][0];
          image_free_particle[i][0][1] = free_particle[i][0][1];
          image_free_particle[i][1][1] = free_particle[i][1][1];
         }
       
        /*If the particle has gone out of bounds, on the left*/
        if(free_particle[i][16][0] == 3.0)
         {
          /*Assign the free_particle the position of the image_free_particle*/
          free_particle[i][2][0] = image_free_particle[i][2][0];
          free_particle[i][3][0] = image_free_particle[i][3][0];
          free_particle[i][2][1] = image_free_particle[i][2][1];
          free_particle[i][3][1] = image_free_particle[i][3][1];
          /*And the x and y velocity of the image_free_particle*/
          free_particle[i][0][0] = image_free_particle[i][0][0];
          free_particle[i][1][0] = image_free_particle[i][1][0];
          free_particle[i][0][1] = image_free_particle[i][0][1];
          free_particle[i][1][1] = image_free_particle[i][1][1];
                   
          /*Return the image_free_particle to position (20.0,20.0)*/
          image_free_particle[i][2][0] = free_particle[i][2][0] - 10.0;
          image_free_particle[i][3][0] = free_particle[i][3][0];
          image_free_particle[i][2][1] = free_particle[i][2][1] - 10.0;
          image_free_particle[i][3][1] = free_particle[i][3][1];
          free_particle[i][16][0] = 0.0;
         }
       
       /*If the particle has gone out of bounds, on the right*/
        if(free_particle[i][16][0] == 4.0)
         {
          /*Assign the free_particle the position of the image_free_particle*/
          free_particle[i][2][0] = image_free_particle[i][2][0];
          free_particle[i][3][0] = image_free_particle[i][3][0];
          free_particle[i][2][1] = image_free_particle[i][2][1];
          free_particle[i][3][1] = image_free_particle[i][3][1];           
          /*And the x and y velocity of the image_free_particle*/
          free_particle[i][0][0] = image_free_particle[i][0][0];
          free_particle[i][1][0] = image_free_particle[i][1][0];
          free_particle[i][0][1] = image_free_particle[i][0][1];
          free_particle[i][1][1] = image_free_particle[i][1][1];
          
          /*Return the image_free_particle to position (20.0,20.0)*/
          image_free_particle[i][2][0] = free_particle[i][2][0] + 10.0;
          image_free_particle[i][3][0] = free_particle[i][3][0];
          image_free_particle[i][2][1] = free_particle[i][2][1] + 10.0;
          image_free_particle[i][3][1] = free_particle[i][3][1];
          free_particle[i][16][0] = 0.0;
         }
        
        /*If the particle is not approaching or passing a boundary*/
        if(free_particle[i][16][0] == 0.0)
         {
          /*Maintain its current position*/
          free_particle[i][2][0] = free_particle[i][2][0];
          free_particle[i][3][0] = free_particle[i][3][0];
          free_particle[i][2][1] = free_particle[i][2][1];
          free_particle[i][3][1] = free_particle[i][3][1];
          /*And current x and y velocity*/
          free_particle[i][0][0] = free_particle[i][0][0];
          free_particle[i][1][0] = free_particle[i][1][0];
          free_particle[i][0][1] = free_particle[i][0][1];
          free_particle[i][1][1] = free_particle[i][1][1];
          
          /*Return the image _free_particle to an arbitrary position*/
          image_free_particle[i][2][0] = free_particle[i][2][0] - 10.0;
          image_free_particle[i][3][0] = free_particle[i][3][0];
          image_free_particle[i][2][1] = free_particle[i][2][1] - 10.0;
          image_free_particle[i][3][1] = free_particle[i][3][0];
          free_particle[i][16][0] = 0.0;
         }
       }
/******************************************************************************/       
       /*Cycle through the image_free_particles*/
       for(i = 0; i < n_max; i++)
       {
        /*If a particle is about to go out of bounds on the left*/
        if(image_free_particle[i][16][0] == 1.0)
         {
          /*Assign an image, that is 10.0 distance units to the right*/
          free_particle[i][2][0] = (image_free_particle[i][2][0] + 10.0);
          free_particle[i][2][1] = (image_free_particle[i][2][1] + 10.0);
          /*And has the same y position*/
          free_particle[i][3][0] = image_free_particle[i][3][0];
          free_particle[i][3][1] = image_free_particle[i][3][1];
          /*And has the same x and y velocity components*/
          free_particle[i][0][0] = image_free_particle[i][0][0];
          free_particle[i][1][0] = image_free_particle[i][1][0];
          free_particle[i][0][1] = image_free_particle[i][0][1];
          free_particle[i][1][1] = image_free_particle[i][1][1];         
         }
         
        /*If a particle is about to go out of bounds on the right*/ 
        if(image_free_particle[i][16][0] == 2.0)
         {
          /*Assign an image, that is 10.0 distance units to the left*/
          free_particle[i][2][0] = (image_free_particle[i][2][0] - 10.0);
          free_particle[i][2][1] = (image_free_particle[i][2][1] - 10.0);
          /*And has the same y position*/
          free_particle[i][3][0] = image_free_particle[i][3][0];
          free_particle[i][3][1] = image_free_particle[i][3][1];
          /*And has the same x and y velocity components*/
          free_particle[i][0][0] = image_free_particle[i][0][0];
          free_particle[i][1][0] = image_free_particle[i][1][0];
          free_particle[i][0][1] = image_free_particle[i][0][1];
          free_particle[i][1][1] = image_free_particle[i][1][1];
         }
        }

/*____________________________________________________________________________*/       
       /*If a wall_particle has gone out of bounds*/
       for(i = 22; i < 44; i++)
        {
         if(wall_particle[i][16][0] == 1.0)
          {
           wall_particle[i][2][0] = wall_particle[i][2][0]-22.0;
           wall_particle[i][16][0] = 0.0;
          }
        }
     time_stamp();
     trace(func_name,action_end);
}
