function my_spaceship(mission) {
    var i = 0;
    var spaceship = {x: 0, y: 0, direction: 'up'};
      
        while (i < mission.length) {
          var manual = mission[i];
          
          if (manual == 'A') {
            accelerate(spaceship);
          }
          else if (manual == "R") {
            turn_right(spaceship);
          }
          else if (manual == 'L') {
            turn_left(spaceship);
          }
          
        i +=1;
        }
    var x = spaceship.x 
    var y = spaceship.y
    var direction = spaceship.direction
      
    return `{x: ${x}, y: ${y}, direction: '${direction}'}`;
      
      function turn_right(spaceship) {
        if (spaceship.direction == 'up') {
          spaceship.direction  = 'right';
        }
        else if (spaceship.direction == 'right') {
          spaceship.direction = 'down'
        }
        else if (spaceship.direction == 'left') {
          spaceship.direction = 'up'
        }
        else if (spaceship.direction == 'down') {
          spaceship.direction == 'left'
        }
      };
      
      function turn_left(spaceship) {
        if (spaceship.direction == 'up') {
          spaceship.direction  = 'left';
        }
        else if (spaceship.direction == 'right') {
          spaceship.direction = 'up'
        }
        else if (spaceship.direction == 'left') {
          spaceship.direction = 'down'
        }
        else if (spaceship.direction == 'down') {
          spaceship.direction == 'right'
        };
      };
      
      function accelerate(spaceship) {
        if (spaceship.direction == 'up') {
          spaceship.y -= 1;
        }
        else if (spaceship.direction == 'right') {
          spaceship.x += 1;
        }
        else if (spaceship.direction == 'down') {
          spaceship.y += 1;
        }
        else if (spaceship.direction == 'left') {
          spaceship.x -= 1;
        };
      };
    
    };
      
