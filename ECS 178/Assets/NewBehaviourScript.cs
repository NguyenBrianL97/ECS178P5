using UnityEngine;
using System.Collections;

public class NewBehaviourScript : MonoBehaviour
{

  
    

    void Start()
    {
     
    }

    void Update()
    {
        
        if (Input.GetKeyDown(KeyCode.W) == true)
        {
            transform.position += Vector3.forward * Time.deltaTime*500;
            transform.Rotate(90, 0, 0);
        }
        if (Input.GetKeyDown(KeyCode.S) == true)
        {
            transform.position += Vector3.back * Time.deltaTime * 500;
            transform.Rotate(-90, 0, 0);
        }
        if (Input.GetKeyDown(KeyCode.A) == true)
        {
            transform.position += Vector3.left * Time.deltaTime * 500;
            transform.Rotate(0, 0, 90);
        }
        if (Input.GetKeyDown(KeyCode.D) == true)
        {
            transform.position += Vector3.right * Time.deltaTime * 500;
            transform.Rotate(0, 0, -90);
        }
        if (Input.GetKeyDown(KeyCode.Q) == true)
        {
            transform.position += Vector3.down * Time.deltaTime * 500;
        }
        if (Input.GetKeyDown(KeyCode.E) == true)
        {
            transform.position += Vector3.up * Time.deltaTime * 500;
        }

    }
}