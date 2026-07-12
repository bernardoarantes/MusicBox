/* /profile/ */

import Image from "next/image";
import { CardMusicReview } from "../components/card_musicReview";

export default function Profile() {
    const username = "Usuario";
    const reviews = 2;

    return(
        <div className="items-center text-center flex flex-col py-5">
            <div className="py-3">
                <p className="maintext">{username}</p>
                <Image src="/assets/Test Account.png" alt="profile default" width={100} height={100} />
            </div>

            <div className="items-center ">
                <p className="maintext">{reviews}</p>
                <p className="subtext">total reviews</p>
            </div>

            <div className="flex-col flex align-left">
                
            </div>
        </div>
    )
}