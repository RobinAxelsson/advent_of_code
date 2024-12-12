#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//https://adventofcode.com/2024/day/9
extern long long pack_and_validate_volume(const char *map, int *buffer_unpacked, int *buffer_empty_slots);

//const char *input = "2333133121414131402";
const char *input = "3740822015781728531051138155528057742888959825191021474914888457168862764614823313573074829676426745286967939577338310244254639270452670662290852539139392506857226452711178484948667163314776488145684598808088936797189259829374747261781596814717947124161019974817451355489116824464697561891590647174752233552836721563888156328833725391722258458383785637465046233078845932526486149722942553723936689926321016264641793213244149847287315973652326783378619932938312645155598372439148771825673227209795638477499027158293432444784998521714354087534219694664144457282549922610167633478565958174691816937075117373933220627340465359173339244150404070239011102232387220827313795686521591657182161660145692666863512812772233408669609390117790291572164615531496632074384922567127999386446680688511633882641511799834116035141424312889673188512958574436999277397191458361506815383577925439266423162921659749508822539120199756127857241244925476715736976629153294183767863324662885985565912212942727351243599494834410258728502999491380396453121364104293107645247642489623823227798715915032342164809197355992289217799656814613227491422024797991153181725350431371546894694910937410614281429653265455676330197294602447224293378062458328824296578326556846341916474685555481195828276849707538279457636896162029876283304778226281447124205682565293552112785814822338522449764314276271258259949279553344924518972516418226163140221872202912847128684976717971932524607434576878701695128850906123188340916895377963433659375222657913572534664911972221571994355692408793292799473028882279239233786641665729699882547436562477127293178272975816597441306771499746152160171439318167267984902386942165691598975914781475952458204160215427234246711324726367521135174568727788158697569233641399574961916989155179344822702996121945465683692469417619835189286313675810728974268521666087567069202015581455363074862413491026972043768667995047195524563962134521592879853216582653318565862945139682389581391871862329146366308133762233899818764717668923369561743039909723727052816260733689938361535593991136949737542552152886344046903070642781926158728383274434589846837948608612638724204866415227825364364660607480249065178035498729883926656390357910795410672324657974217161671737992738238987555120301330504245816729867693394046145652136117803056242260758951278753622281785321648651443511282446294562373453654051304981683198495692328943167983542956576541772959698496638611428341938578396846165233324128506865283775976239596442477238932971524067975657849863682642324520278657903934115545934657596416119631234672791980278658473781805567423136597424146617405694506068785549976195253560516963927274146161767381577479585698403020109990955547277591797724795721497252234098336539521580448955265324303831591398922056751487794353883863553096464382615094712030266046666838953377634720204314628664242223461993934599861763689436499035241042251389676839674197753477105640801763586575965511373495481580669685357962208893185362727554902679979651766118656763994271678557909179596559581997822978379851369381972057615087146669223097605079844825827132185138886624189137805686428958769750462823288018803563199517961967854892453169602758561883754366614937486330646394418997914244814415659636546045168477613463862055765131256255453133895947963143535389215541423525511838415335845685905049206284407429707564781310939518636594503466437436774715296272521336686140949665499537188753159969398460824455631295453683975994758526765246705924207194685127856375163447229654755478215211515282208751964841479724867548849721919916116529655879205517144430254289435016119153888027579733833468251487575750227379314093299172907837626048854823134124933286363363333736772244756386839878999876589197776364157213934469885710423534164126887562224661302942456440347229571386289145103670501155534061291862918280476590678364871534871749111849987917653739418156607386628577903010399635682440518783994223904937586325586491982571808833877567235843783412343878999169373137923424465352207937612156192293837291105174727552675459185641577681192032506463829842437137435371436175937456128798944139466039397118434130705336801258206198625976806584719381564996625261899155449588335225689310727380338061829685141335675942955180203382124360112962834813582266249711788444906942182824219369331954996871919395877955746498574465142864409269654666299652267271175869336251537183205320383728186734895727542311345166619583809577684791862471302740264516288657941676814921969290299779328872666893243375582560138240225123212854304624424128816827567140473184312863178690611928468770912191162265873563609419713332382034429368918771179281198053106452157579358529481517255692983415219144953486218661919246218228914128735539634364584066526883994348633450537413867874372155133632271374841284151150582582556314421462271462561149645530164657236825525544638956559772147448812239382538378023415569912482306711952994681284247077806089501229853893238263955727844366772486539513921916963978241157154077319397706168664289864327133186196268906834983935928644726655965173993518757674963392728078762330491711868625799535418356864373583020294838747471413640605280531475279770744123785726675688159381838962633193403296527949696297154561612966629922903730876597972494618293476764388846104329555359859082991594667058524553933146561598562324442232572178507191229411312355192264117499756591324619832160838650193138873036163298598771678587356846903999667231998993688496838053747760543597568756419075389533675221193454683249965088431486817571664025714398139644854977505670544024739939935781477911631551449033252168708079606424386368159867352755634136581581134993912080655081264033624253494182697288127889521144372669958870551659579417192247146652476454584286991432666740931529637468723087448759742656991199219277767331688470568368452267512797155974609725181047887988355017419347518922477018537473238257103662243091279476648611435034837178776914202610809498998429606176343173306185449510861058935656857598436537368875821781358052611748779224975826387430557511544597122339853035355323339186951247837638972970673189938869605083946312623242227762432395743324953570109482532715577512544730697334872868363084289220508822956880591112828089205642335087767384206856982859829575573467931629366373929195344157787162974065375284484294449925521434692368172410482140221942948378551991211781436039914123821644802437831216899797531229773737261986649986819857952596956030826071729216786535266894773963246473701892227478862816486096454053655556166792933678459254517033645539519385821771131388114780397046492755517687368187262495476743856792522580812426614083636172723148236321408184209999924445748563878455965952906188246462301019881138144343966826772136786774597711671263622532749428413063393595872747342232687493462944901519809797415085911152101579105776951771729660604816811898865441117547997083531279384843146586892465154014232057961032814685271151539477845129568826118956514225357931807922963594521292887065297466314973334595573844953070336942919479989913542331962314537178196918776165922937394512702887468361469348194042259679446513952783699289496593703652273250428512314440957552131469206156215131516115985478177585498841923040254554156371351523602044444645712047499761489766346488164530953426544866427719215986413452116694884120363083951998436590221363207137202892944329866718641471877512767659896684833196166431386231653870696815777614509595163955481946127953129012207034993341728018286986211340351333975561235471156134994469666260785350767292681251813218608618561547836418579367617666456470199956461643903665611221562454594885722414527294273819223046454892722780762646741741293257229476638625401567973593942166857850604846395222232853882266123895385330199658563755578196831887625825423583607813818538689935607026356218981218829574632735402276506755331171635191537171325888959047801986173986522050956230595143418822149733188027319613211834851951627429507577206852892952449934382078338167637820928194938593404025959042297422936168432369755958786632408584402268396142383971739231963128964549525531473246483816383126699035141663869835703226987776967893105872227527386672256199924561256260158674937794415167489391188464838862367283112131974627718564808241566028463826712027286976346358439421493546562260586360957279586925103438799774508149508467134971989155612573859998667314922632144980214579274749882983183919704629903742134560242831204927443610148261526816263268165668579776498458133724972637909566466756863755344973578752945283457293716658497852511175956572886420436295725720766274259999418738327634825916376014707440694311178188992582262824999359944852978164614812237395836649841979505577558452396411381132272679935449835744718150475157204692961769667333372935786331861447806629387289902575364315117782876192532688548131574442164082939515759245897233611179879452763848231749574499327981378491533360146355575411504154467117115824298397184796959182516761697032399719343553684119546085982914672116391997211232187827173866271795918164805080199229994021916779471885567375167631846352963198224993826678976719329387482543854146787719573192412416526558501366173046674978726655134565118037824973726544352197647159731436526282307636135587321334776858764817694236505727284427779936232295991196158996577926392015973787903322302151543989368218381123434333103621577866583444624587261743165454105538116140832526177949402468365092132724366090994940728218923414389452738669527597154557841231625559156960102732484628611697845538675358523948929318539524222477466038853734887224775895393117974377553676277722659828748317724574639660544987729051492213442140507760305733436464142314278592362742612198168363144293867649993754369292975574926025697324854140843415827396476274756675743840741332299248414714164915775384627346304821292519913827976260683599967746697678807617363967245276524329925447798057782833553249926756881041437757719221567545511274337223237858977197244963202665984848921258812767964235588421717542809083459786206246908192499927896826502514765224689632241080192530728078118318919798744686202053166237415038191581856282961697677770692195778922931754178485764343655073821257394415376142344294783416496228794869346844142346118744107021798450739388783360169220854723174985395631238224492837359626134687192338866187274037948949605573334350261949659627466581932726832812454018539816388268445536995811109158579520611424729237237711797391767613645016885454716568469019989213921786263025426086888157646225537754472040581933802169698580504051149984355026341855678210468190887420371352284886186333547341304281555720277596324038705633897628558199749965729289276015346294576266895374936455336696477977419861345146264192979140126870774622363726677492641116326672462621475265803881739974817870132160115840487327382794333499872531842177874045656312555071371496723077973719234935946937442158847186708818466399797017753332671051849567156176228921111311291846112929183190311468213852891734153869235516464187762663325565634936475791385141716220674646751890242547544757317796742310229269822926869339833637386244505681665836727785794193566194678214109228111056773828991676682822557141534775725440112811586988845732566336879880637834834725927930585137894043531632289980947977269812826287361848334051508093468774564476218292678981824131499542303551206493221454487663516543592423166262703187918898732087261576234370505523387939438981873924148634529993931669824431808484749148744480894280675648529333415983293382163046371855319894278725386696159076171533785215233077543582715693204258932718297930292864677738709393576056839148694066251255524950147186213890188985386370132868927835843284544293417695817540716175663032168822914359979987869233147029313091431554355661475796408282113653951816585780284720354286412774718083531036606132903026943880874818279749229845954379297253106693938589404428458016481564337380754686885595692464971596189872418854367053853472511771374347567065605149373479206534574855482799692784452148584569354635172467348466156156252791521588102027662734433428469129182617414881372756847283532819571356393224625993146531185229446763481256457279156771213834471285383193843211905412133378569945752858581876178092715366936516464929937936578996945876321392823070816251978661442731934366257220292549301295342070553917614923572132608910315362593472314959248244561258793521623931828957789895579331722984746461273596454814969514729538776169797830548855511016161628156893935257634890519088668060638122755956823828157696625754535952911658355881558283594967318631335212695966771562213379554946753143803112894247727119763691927687302211822061744757874176932576629767498027605690672229957564942285733426973047143753993056135016607817992861848285573984955970198110219914245055935330708926591128988974539747258634789778659466631589836988886680102220964636832473303861653179158224671563141571882463355130557451661515434212466085868196972411902327483626218398707999975217647497329553771815971778266886773498111432434258181729217499549948466911671817796271691543315776453612844572703123536496529647636045502451264952206238165194859197477235903191564893336033488715356454956467349333856444639570736591765376888781934871653225875025173095447050417190842253133242993433114593145366527751587917982381489438403793369766363624122790582063306290939425852732341926176257734420339253283048915828818675242716715945174166753421206471348349276262795656926342888288258875392410317021707017367098978662292471716296709932651523336098967936141960602462865920797786772364757168603763264541952634416975846538844333697084389727835776592575729115966219828245455556638076303614673483717768984113908246217455372337528077525027122545831415824299673877189938808263851680193064337594742292246399631575187679584610487712571280928497216932403341591323893632778729707589108813466929222994641374546219445635666280796740413797127537126394178139434468772430655460845587669157236876155955359412856952869436375180191074116933615746397265978173763798972560352950105454138497268540825527427574223864926338109753534396389128673669908916334012452638774691316871322835208121694025104022216914112269305623221552916231273593872223982465415121991443787775713485575458521376739994907734655030667898398056437175409947202599423910251667692888321032556387165460214390312969455470569457307173746283698938112869406945862358463811877693938824898438467795299927128153687372698766117354336925701083342254504741343780862320971712222257274443862736411775438952471017173666877420116539818170543071305052979843557534513911854687137568801536771822163878859636916276335660802881107793982894849462579868376718171263953527908251161918386864456318678112324259778291509275748959847023359426402179384233834463964443889633205591918825721658332821492835295048674764425883247169365388608071996277268229368287712593344332808810288032218392839859242651829991476243893934678380791418301686279697246998441460279220771873147018341154607715851551365113348615963594729441178314826353863820213557385473738138349352192864124350253678888572428347354036409625333338163146475640208386505580132143466413773720523698804035235377413050563393981779858489717075559034422731533577894921633839309157228046833742614968348074767130704686238143305014357852815733293235225496533590154026206796266851144950402299349312178339773031684282986225606476117272133515831528196439724360591794792113246987356191768035837117162270599298808769706087415350516587379417362272289114456379328062226726723378761471109828747496162231187077707269466020837769975515265144925955124836338637305259832042181674489043486431698299559439166037606525453630725055101125272639794130453618473394854511514468863446697383591988368226794874696466901287488733994414543440266186769638419157918424822661109528372053689025683663107249789337375246859927523554893495865855405054578239435410949423131633857516529044184583302330109872557433287724808954632649874847816238779351564277184366194441719310895653795617238163419772855319457053151787647935903823242042202347458927631423647159789979272771622492617274246341804620832575778891699128555865574945891932408287428178386923437837587026621767192643985955931696305342819897679644174027893067429660457374723933256182536639936743248423702288178357456524665850522927784015543511157075756286521148356161461553182571362419139981199340426299539592218259723357823992494853232674281269341449274095793529481017801332414025933630925623453539907599219160759630121267694094157856622099189521613127161456752454277714155453239771963078357072935877109216262410651910683748176658674944429396777974687742287114143055507126359650128243997669205289424631436527196868247046514225614277558344987281589167466526724175748880302086105241274372723953229618966161214469261670505643207433707486513235341343712666488489233636903154745469401699564024229553162733383334435199984978174480293983669789846019872683394774244449461498619766358122984626821362672665481212963162483097422494893386478896345937798286976771705171756530216340183233905039724237967086595129134044412030147714764071307364982874728743585713762816349016886746374899734668766735716633549917475170421157368433893268329735512741901731389857959014884269103077964327291872148975338967167412271289822417539429266953133211799071609699362478279630964123582621989013992745387764109074606256331479633315742220537676317593864897425240157891456083219525621498245957555066702636555666339131402629944327143521102217449134518749706391848115399319773918784521643635617155853471818010744456268741483843922738995862271779297492432781422254353690303884264520813531411065185627235241804071417365991183146575889782363839452795113595706529427922716937241441542347602341353618475036387892861982846818509836751048717875618818265264835698784848219221669566791989656620713772668713457420654841861832304419809014193667559033863784213729806150197697556940646810634574966586897947171492357794218231772850345333445743313189154094541267795493946392109618326034482527272181255226505844291815977522531437182693996690948736456444497077611423255740823460615470582122124643731543409315892028142781897914734571267990486183262981368738701072791940327472534094446618678979788121976932842395138052947315426513917113341676237074218499486333161655852063602294865279564939784754831792856436263948738732163980667899366174963042593980862846129990238850595526819440604794216680705260159110994880854885591776594031123631304386586444938692102366563111594381193876979212857247599343225818358987981574926541369231713542139171894492575372449397222981869995121654685443393298358013123896466883129724117158649565902260446864401972426518188057874199151977632829673115708163223925731712633432855659113055788022392415482126573213675645679799708964862647556662473451305812813567819289121873145493725686932070531926556023702163456439442629489224841335265710262326222287846519668917528747233521169966885259298067149933337150663083626439579516741059516174849171726977287792748986138344395968209790394021137435231928737342571129273277137048804980158041391383301976641151166836775163553938177941485563412229221495302019875569969468399384378184812011724270431682496738803786925285361886389595649727885954962849693746821740729659449281793152535548535078692410489556607448496367332781689281954585859455743074284547782924609672725352428548851315419918411126247449133461591378913428906565883043554079561890332289785975984576785366482947425338634736929983977526723640925910909383133933249340886510468797491364335322626837363569274889781719852833604163297890721186876919288217911347309588445178902468234026286269562563973663914124395345954244478174575229458559978446734759758469488379136653252342655584296097853873368424233715307952543566353986615575766694304965833463468316119722927793494769185319698353723919541075709761462083221697594139159983107837358911836069603121453499334767751172467893107656799626808036804097123843858142541119447992436770123639848041926847644618548130509010108710194541961925128213293318898330568941596648564549948789271656512558791416465510285774718714419540201148356";

    int buffer_unpacked[262144];
    int buffer_empty_slots[262144];

int main(int argc, char *argv[])
{

    long long checksum = pack_and_validate_volume(input, buffer_unpacked, buffer_empty_slots);
    printf("%ld", checksum);
    //right answer is 6299243228569

    return 0;
}