<?php
  $statusmsg = "";
  $rcv_message = "";

  if(isset($_POST['tShelfID']))
  {
    publish_message($_POST["tShelfValue"], $_POST["tShelfID"], 'localhost', 1883, 5);
  }

  $shelfs = array(0,0,0,0,0,0,0,0,0,0,0,0);
  $allamps = 0;

  read_topic('unit1/#', 'localhost', 1883, 60, 2);	
  read_topic('unit2/#', 'localhost', 1883, 60, 1);	
  read_topic('allamps', 'localhost', 1883, 60, 1);	
  echo '<script type="text/javascript">'."\r\n";
  echo 'var shelfs = [';
  
  for($x = 0; $x < 12; $x++) 
  {
    if(0 != $x)
    {
      echo ',';
    }
    echo $shelfs[$x];
  }
  
  echo ']; var ';
  echo 'allamps='.$allamps;
  echo';</script>';

  function publish_message($msg, $topic, $server, $port, $keepalive)
  {
    $client = new Mosquitto\Client();
    $client->onConnect('connect');
    $client->onDisconnect('disconnect');
    $client->onPublish('publish');
    $client->connect($server, $port, $keepalive);

    try 
    {
      $client->loop();
      $mid = $client->publish($topic, $msg, 1, true);
      $client->loop();
    }
    catch(Mosquitto\Exception $e)
    {
      echo 'Exception';
      return;
    }

    $client->disconnect();
    unset($client);					    
  }

  function read_topic($topic, $server, $port, $keepalive, $timeout)
  {
    $client = new Mosquitto\Client();
    $client->onConnect('connect');
    $client->onDisconnect('disconnect');
    $client->onSubscribe('subscribe');
    $client->onMessage('message');
    $client->connect($server, $port, $keepalive);
    $client->subscribe($topic, 2);

    $date1 = time();
    $GLOBALS['rcv_message'] = '';

    while (true) 
    {
      $client->loop();
      $date2 = time();

      if (($date2 - $date1) > $timeout)
      {
        break;
      }
    }

    $client->disconnect();
    unset($client);
  }

  function connect($r) 
  {
    if($r == 1)
    {
      echo "{$r}-Connection refused (unacceptable protocol version)|";
    }

    if($r == 2)
    {
      echo "{$r}-Connection refused (identifier rejected)|";
    }

    if($r == 3)
    {
      echo "{$r}-Connection refused (broker unavailable )|";        
    }
  }
 
  function publish() 
  {
    global $client;
  }
 
  function disconnect() 
  {
    // no body
  }


  function subscribe() 
  {
    //**Store the status to a global variable - debug purposes 
    $GLOBALS['statusmsg'] = $GLOBALS['statusmsg'] . "SUB-OK|";
  }

  function message($message) 
  {
    global $shelfs;
    global $allamps;

    if('allamps' == $message->topic)
    {
      $allamps = $message->payload;
    }
    else
    {
      // unit1/shelf1 6
      $unit = substr($message->topic,4,1);
      $shelf = substr($message->topic,11,1);
      $index = (($unit - 1)*6)+($shelf-1);
      $shelfs[$index] = $message->payload;
    }
  }
?>


<html>
  <head>
    <meta charset="UTF-8">
    <title>Jim's Display Cabinet</title>

    <link rel="stylesheet" type="text/css" href="css/lib/control/iconselect.css" >
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js"></script>
    <script type="text/javascript" src="lib/control/iconselect.js"></script>
    <script type="text/javascript" src="lib/iscroll.js"></script>
    <script type="text/javascript">

      var iconSelectors = [];

      window.onload = function(){
      var theParams = {'selectedIconWidth':100,
      'selectedIconHeight':62,
      'selectedBoxPadding':1,
      'iconsWidth':30,
      'iconsHeight':18,
      'boxIconSpace':1,
      'vectoralIconNumber':4,
      'horizontalIconNumber':4};

      iconSelectors.push(new IconSelect("Unit1Shelf1",theParams,"unit1/shelf1"));
      iconSelectors.push(new IconSelect("Unit1Shelf2",theParams,"unit1/shelf2"));
      iconSelectors.push(new IconSelect("Unit1Shelf3",theParams,"unit1/shelf3"));
      iconSelectors.push(new IconSelect("Unit1Shelf4",theParams,"unit1/shelf4"));
      iconSelectors.push(new IconSelect("Unit1Shelf5",theParams,"unit1/shelf5"));
      iconSelectors.push(new IconSelect("Unit1Shelf6",theParams,"unit1/shelf6"));
      iconSelectors.push(new IconSelect("Unit2Shelf1",theParams,"unit2/shelf1"));
      iconSelectors.push(new IconSelect("Unit2Shelf2",theParams,"unit2/shelf2"));
      iconSelectors.push(new IconSelect("Unit2Shelf3",theParams,"unit2/shelf3"));
      iconSelectors.push(new IconSelect("Unit2Shelf4",theParams,"unit2/shelf4"));
      iconSelectors.push(new IconSelect("Unit2Shelf5",theParams,"unit2/shelf5"));
      iconSelectors.push(new IconSelect("Unit2Shelf6",theParams,"unit2/shelf6"));

      var icons1 = [];
      icons1.push({'iconFilePath':'images/Off.jpg',    'iconValue':'01'});
      icons1.push({'iconFilePath':'images/Blue.jpg',   'iconValue':'02'});
      icons1.push({'iconFilePath':'images/Green.jpg',  'iconValue':'03'});
      icons1.push({'iconFilePath':'images/Orange.jpg', 'iconValue':'04'});
      icons1.push({'iconFilePath':'images/Purple.jpg', 'iconValue':'05'});
      icons1.push({'iconFilePath':'images/Red.jpg',    'iconValue':'06'});
      icons1.push({'iconFilePath':'images/White.jpg',  'iconValue':'07'});
      icons1.push({'iconFilePath':'images/Yellow.jpg', 'iconValue':'08'});
      icons1.push({'iconFilePath':'images/Alien.jpg',  'iconValue':'09'});
      icons1.push({'iconFilePath':'images/Fire.jpg',   'iconValue':'10'});
      icons1.push({'iconFilePath':'images/Lava.jpg',   'iconValue':'11'});
      icons1.push({'iconFilePath':'images/Ocean.jpg',  'iconValue':'12'});
      icons1.push({'iconFilePath':'images/Space.jpg',  'iconValue':'13'});
      icons1.push({'iconFilePath':'images/Swamp.jpg',  'iconValue':'14'});

      for (i = 0; i < iconSelectors.length; i++) 
      { 
        iconSelectors[i].refresh(icons1);
        iconSelectors[i].setSelectedIndex(shelfs[i]);

        var cb = document.getElementById(iconSelectors[i].getID());
        cb.addEventListener('changed', 
          function (e) 
          { 
            for (j = 0; j < iconSelectors.length; j++) 
            {
              if(e.target.id == iconSelectors[j].getID())
              {
                var theForm, newInput1, newInput2;
                // Start by creating a <form>
                theForm = document.createElement('form');
                theForm.action = '/Cabinet/Cabinet.php';
                theForm.method = 'post';
                // Next create the <input>s in the form and give them names and values
                newInput1 = document.createElement('input');
                newInput1.type = 'hidden';
                newInput1.name = 'tShelfID';
                newInput1.value = iconSelectors[j].getTopic();
                newInput2 = document.createElement('input');
                newInput2.type = 'hidden';
                newInput2.name = 'tShelfValue';
                newInput2.value = iconSelectors[j].getSelectedIndex();
                // Now put everything together...
                theForm.appendChild(newInput1);
                theForm.appendChild(newInput2);
                // ...and it to the DOM...
                document.getElementById('hidden_form_container').appendChild(theForm);
                // ...and submit it
                theForm.submit();

                break;
              }
            }
          }, false);
      }
    };

    </script>
  </head>
  <body>
    <table>
      <tr>
        <td>
          <center><h2>Jim's Display Cabinet</h2></center>
        </td>
      </tr>
      <tr>
        <td>
          <table width="550" border="1">
            <tbody>
              <tr>
                <th scope="col">Unit 1</th>
                <th scope="col">Unit 2</th>
              </tr>
              <tr>
                <td><div id="Unit1Shelf1"></div></td>
                <td><div id="Unit2Shelf1"></div></td>
              </tr>
              <tr>
                <td><div id="Unit1Shelf2"></div></td>
                <td><div id="Unit2Shelf2"></div></td>
              </tr>
              <tr>
                <td><div id="Unit1Shelf3"></div></td>
                <td><div id="Unit2Shelf3"></div></td>
              </tr>
              <tr>
                <td><div id="Unit1Shelf4"></div></td>
                <td><div id="Unit2Shelf4"></div></td>
              </tr>
              <tr>
                <td><div id="Unit1Shelf5"></div></td>
                <td><div id="Unit2Shelf5"></div></td>
              </tr>
              <tr>
                <td><div id="Unit1Shelf6"></div></td>
                <td><div id="Unit2Shelf6"></div></td>
              </tr>
            </tbody>
          </table>
        </td>
      </tr>
      <tr>
        <td>
          Drawing: 
          <script type="text/javascript">
              try
              {
                document.write(allamps);
              }
              catch (e) 
              {
                // Do nothing
              }
          </script>
          Amps
        </td>
      </tr>
    </table>
    <div id="hidden_form_container" style="display:none;"></div>  
  </body>
</html>
